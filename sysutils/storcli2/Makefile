PORTNAME=	storcli2
DISTVERSION=	8.17
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/
DISTNAME=	StorCLI_Avenger_8.17_08.017.000.0008
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	SAS4 MegaRAID FreeBSD StorCLI2
WWW=		https://www.broadcom.com/support/

LICENSE=	storcli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See ${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	binaries only available for amd64
USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	sbin/storcli2
PORTDOCS=	ThirdPartyLicenseNotice.pdf readme.txt
OPTIONS_DEFINE=	DOCS
BINSRC=		${WRKSRC}/storcli_rel/Avenger_StorCLI

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
DOWNLOAD_URL=	${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}
IGNORE=		you must manually fetch the distribution file \
		(${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, \
		place it in ${DISTDIR}/${DIST_SUBDIR} and then run make again
.endif

post-extract:
	@${TAR} xf ${BINSRC}/FreeBSD/storcli2.tar -C${WRKSRC}
	@${ECHO} "[" > ${WRKDIR}/pkg-message
	@${ECHO} "{" >> ${WRKDIR}/pkg-message
	@${ECHO} "  message: <<EOM" >> ${WRKDIR}/pkg-message
	@${FMT} 75 79 ${BINSRC}/readme.txt >> ${WRKDIR}/pkg-message
	@${ECHO} "EOM">>  ${WRKDIR}/pkg-message
	@${ECHO} "}" >> ${WRKDIR}/pkg-message
	@${ECHO} "]" >> ${WRKDIR}/pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/storcli2 ${STAGEDIR}${PREFIX}/sbin/storcli2

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${BINSRC}/ThirdPartyLicenseNotice.pdf \
		${BINSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
