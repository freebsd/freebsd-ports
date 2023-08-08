PORTNAME=	storcli
DISTVERSION=	7.2309
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/
DISTNAME=	Unified_storcli_all_os_7.2309.0000.0000

MAINTAINER=	takefu@airport.fm
COMMENT=	SAS MegaRAID FreeBSD StorCLI
WWW=		https://www.broadcom.com/support/

LICENSE=	storcli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See https://www.broadcom.com/company/legal/licensing
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	sbin/storcli
BINSRC=		${WRKSRC}/Unified_storcli_all_os

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
DOWNLOAD_URL=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/${DISTNAME}${EXTRACT_SUFX}
IGNORE?=	You must manually fetch the distribution file\
	(${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL},\
	place it in ${DISTDIR} and then run make again
.endif

post-extract:
	@${TAR} xf ${BINSRC}/FreeBSD/storcli64.tar -C${WRKSRC}
	@${ECHO} "[" > ${WRKDIR}/pkg-message
	@${ECHO} "{" >> ${WRKDIR}/pkg-message
	@${ECHO} "  message: <<EOM" >> ${WRKDIR}/pkg-message
	@${FMT} 75 79 ${BINSRC}/readme.txt >> ${WRKDIR}/pkg-message
	@${ECHO} "EOM">>  ${WRKDIR}/pkg-message
	@${ECHO} "}" >> ${WRKDIR}/pkg-message
	@${ECHO} "]" >> ${WRKDIR}/pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/storcli64 ${STAGEDIR}${PREFIX}/sbin/storcli

.include <bsd.port.post.mk>
