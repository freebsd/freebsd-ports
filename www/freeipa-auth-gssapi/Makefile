PORTNAME=	freeipa-auth-gssapi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.5
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Apache mod_auth_gssapi built against MIT krb5 for FreeIPA
WWW=		https://github.com/gssapi/mod_auth_gssapi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf apache bison gssapi:mit,flags libtool pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	gssapi
GH_PROJECT=	mod_auth_gssapi
MODULENAME=	mod_auth_gssapi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	KRB5_CONFIG=${KRB5CONFIG} \
		OPENSSL_CFLAGS=-I${OPENSSLINC} \
		OPENSSL_LIBS=-lcrypto

# Independent build of mod_auth_gssapi, hard-wired to the MIT (security/krb5)
# GSSAPI so it matches the rest of the FreeIPA stack (freeipa-server, gssproxy).
# www/mod_auth_gssapi defaults to GSSAPI_BASE on FreeBSD 15/16, which mixes base
# and port MIT krb5 in one httpd process and breaks gssproxy interposition
# (gss_acquire_cred fails), so FreeIPA needs the MIT-linked build.
CONFLICTS_INSTALL=	ap24-mod_auth_gssapi

APMOD_FILE=	240_${MODULENAME}.conf.sample
SUB_FILES=	${APMOD_FILE}
PLIST_FILES=	@sample\ ${APACHEETCDIR}/modules.d/${APMOD_FILE} \
		${APACHEMODDIR}/${MODULENAME}.so
PLIST_SUB=	APMOD_FILE=${APMOD_FILE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		  ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${APXS} -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		-i -n ${MODULENAME} ${WRKSRC}/src/${MODULENAME}.la
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

.include <bsd.port.mk>
