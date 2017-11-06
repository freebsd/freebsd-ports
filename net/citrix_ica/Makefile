# Created by: msmith
# $FreeBSD$

PORTNAME=	citrix_ica
PORTVERSION=	13.6.0
CATEGORIES=	net comms linux
MASTER_SITES=	#
DISTNAME=	linuxx86-${PORTVERSION}.10243651

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Citrix(R) Presentation Server(TM) client

ONLY_FOR_ARCHS=	i386 amd64
USES=		fakeroot linux webplugin:linux
USE_LINUX=	alsalib gtk2 libxml2 openmotif
WEBPLUGIN_DIR=	${PREFIX}/ICAClient
WEBPLUGIN_FILES=	npica.so
RESTRICTED=	License prohibits redistribution

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CDIR=		${PREFIX}/ICAClient
CERTDIR=	${CDIR}/keystore/cacerts

PLIST_SUB=	MOZILLA_HOME=${MOZILLA_HOME}

.if defined(ICA_CERTS)
PLIST_SUB+=	HAVE_ICA_CERTS="" ICA_CERTS="${ICA_CERTS}" CERTDIR="${CERTDIR}"
.else
PLIST_SUB+=	HAVE_ICA_CERTS="@comment "
.endif

SUB_FILES=	wfcmgr wfica
SUB_LIST=	CDIR=${CDIR}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=May not be redistributed due to licensing. Please visit https://www.citrix.com/downloads/citrix-receiver/linux/ accept their license and download ${DISTFILES} into ${DISTDIR}
.endif

.if defined(ICA_CERTS)
.for f in ${ICA_CERTS}
PLIST_FILES+=	${CERTDIR}/${f}
HASH_${f}!=	openssl x509 -noout -hash -in ${DISTDIR}/${f}
PLIST_FILES+=	${CERTDIR}/${HASH_${f}}.0
.endfor
.endif

pre-fetch:
.if defined(ICA_CERTS)
.for f in ${ICA_CERTS}
	@echo "Checking ${f}"
.if !exists(${DISTDIR}/${f})
	@echo "Cert ${f} not found."
	@exit 1
.endif
.endfor
.endif

post-patch:
# - linux syscall epoll_create is not yet implemented
# - disable Flash redirection as it generates a deadlock in linux_sys_futex
	@${REINPLACE_CMD} \
		-e 's|^ClientAudio=On|ClientAudio=Off|' \
		-e 's|^FlashV2=On|FlashV2=Off|' \
			${WRKSRC}/linuxx86/linuxx86.cor/nls/*/module.ini
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${STAGEDIR}${PREFIX}|g' ${WRKSRC}/linuxx86/hinst

do-install:
	@if (test -d "${CDIR}") ; \
	then \
		${ECHO} "-----------------------------------------------------------" ; \
		${ECHO} "" ; \
		${ECHO} "A ${CDIR} installation does already exist." ; \
		${ECHO} "Please move it away or delete the old port" ; \
		${ECHO} "" ; \
		${ECHO} "-----------------------------------------------------------" ; \
		${FALSE} ; \
	fi
	cd ${WRKSRC} && ${FAKEROOT} ${SH} -c './setupwfc'
	${INSTALL_SCRIPT} ${WRKDIR}/wfcmgr ${STAGEDIR}${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKDIR}/wfica ${STAGEDIR}${PREFIX}/bin/wfica
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".
	${MKDIR} ${STAGEDIR}${CDIR}
	${MKDIR} ${STAGEDIR}${CDIR}/config
	cd ${WRKSRC}/linuxx86/linuxx86.cor/ && ${COPYTREE_SHARE} . ${STAGEDIR}${CDIR}
	${CP} ${WRKSRC}/setupwfc ${STAGEDIR}${CDIR}

.if defined(ICA_CERTS)
	${MKDIR} ${STAGEDIR}${CERTDIR}
.for f in ${ICA_CERTS}
	${INSTALL_DATA} ${DISTDIR}/${f} ${STAGEDIR}${CERTDIR}
	${LN} -sf ${f} ${STAGEDIR}${CERTDIR}/$$(openssl x509 -noout -hash -in ${DISTDIR}/${f}).0
.endfor
.endif

.include <bsd.port.post.mk>
