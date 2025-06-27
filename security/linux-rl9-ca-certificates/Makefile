PORTNAME=	ca-certificates
PORTVERSION=	2024.2.69
DISTVERSIONSUFFIX=	_v8.0.303-91.4.el9_4
PORTREVISION=	4
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mozilla CA root certificate bundle (Rocky Linux ${LINUX_DIST_VER})

LICENSE=	PD

USES=		linux:rl9
USE_LINUX=	p11-kit
USE_LINUX_RPM=	noarch

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# Here we perform a dance to properly regenerate the trust store

# 1. We need to run these tools as a non-root user, otherwise they don't pick
#    up our config: https://github.com/p11-glue/p11-kit/blob/1bbd6db36b68cae074b35845c212c7d9a8ba19fe/p11-kit/conf.c#L249-L251
.if ${UID} == 0
SU_NOBODY=	/usr/bin/su -m nobody -c
.else
SU_NOBODY=	${SH} -c
.endif

post-stage:
# 2. Create a hacked copy of update-ca-trust that is permitted to look into
#    user-supplied config.
	${SED} '/export P11_KIT_NO_USER_CONFIG=1/d' \
		${STAGEDIR}/${PREFIX}/usr/bin/update-ca-trust > \
		${WRKDIR}/update-ca-trust-staging
	${CHMOD} +x ${WRKDIR}/update-ca-trust-staging
# 3. Prevent update-ca-trust-staging from operating on ${LINUXBASE}. We want
#    it take inputs from ${STAGEDIR} and output into ${STAGEDIR}.
#    To achieve that, an undocumented feature is employed that can be tracked
#    through the following place in the code:
#    a. https://github.com/p11-glue/p11-kit/blob/1bbd6db36b68cae074b35845c212c7d9a8ba19fe/p11-kit/modules.c#L641-L658
#    b. https://github.com/p11-glue/p11-kit/blob/1bbd6db36b68cae074b35845c212c7d9a8ba19fe/trust/module.c#L409
#    c. https://github.com/p11-glue/p11-kit/blob/1bbd6db36b68cae074b35845c212c7d9a8ba19fe/trust/module.c#L293-L296
#    Without this hack the /bin/trust program always use hardcoded paths that
#    point to ${LINUXBASE} as evidenced by
#    d. https://github.com/p11-glue/p11-kit/blob/1bbd6db36b68cae074b35845c212c7d9a8ba19fe/trust/module.c#L416C77-L416C88
	${MKDIR} ${WRKDIR}/.config/pkcs11/modules
	${SED} "s|x-init-reserved:|x-init-reserved: paths=${STAGEDIR}/${LINUXBASE}/etc/pki/ca-trust/source:${STAGEDIR}/${LINUXBASE}/usr/share/pki/ca-trust-source|" \
		${LINUXBASE}/usr/share/p11-kit/modules/p11-kit-trust.module > \
		${WRKDIR}/.config/pkcs11/modules/p11-kit-trust.module
# 4. If we're building as root, the nobody user wouldn't be able to write into
#    ${STAGEDIR}. Change the owner to allow that.
.if ${UID} == 0
	${CHOWN} -R nobody ${STAGEDIR}
.endif
# 5. Run the actual generation step.
	${SU_NOBODY} 'cd ${STAGEDIR} && ${LINUXBASE}/bin/env XDG_CONFIG_HOME="${WRKDIR}/.config" \
		../update-ca-trust-staging extract \
		-o ./${PREFIX}/etc/pki/ca-trust/extracted'
# 6. Reforge symlinks into relative ones to prevent Linuxulator from resolving
#    them into /etc. We want symlink targets to point into /compat/linux/etc.
	${FIND} ${STAGEDIR}${PREFIX} -type l -exec \
		${SH} -c "tgt=\$$(readlink {}) ; [ \$$tgt != \$${tgt#/} ] && ${RLN} ${STAGEDIR}${PREFIX}\$$tgt {}" \; || ${TRUE}

# Verify that we actually generated something. To make sure that ${LINUXBASE}
# does not affect the generation the testing should be performed this way:
# 1. Get into jail:
#    poudriere testport -i
# 2. Test with package installed:
#    make test
# 3. Rebuild with package installed:
#    make clean stage
# 4. Check that the result is the same:
#    make check-plist test
# 5. Deinstall the package:
#    make deinstall
# 6. Check that the result is the same:
#    make test
do-test:
	${SU_NOBODY} '${LINUXBASE}/bin/env XDG_CONFIG_HOME="${WRKDIR}/.config" \
		/bin/trust list' | wc -l | ((read count ; [ $$count != 0 ]) && ${ECHO_CMD} ok)

.include <bsd.port.post.mk>
