PORTNAME=	storcli
DISTVERSION=	7.3503
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/host-bus-adapters/host-bus-adapters-common-files/sas_sata_nvme_12g_p35/
DISTNAME=	STORCLI_SAS3.5_P36
DIST_SUBDIR=	${PORTNAME}${DISTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	SAS MegaRAID FreeBSD StorCLI
WWW=		https://www.broadcom.com/support/

LICENSE=	storcli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See https://docs.broadcom.com/docs/${DISTNAME}${EXTRACT_SUFX}
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	binaries only available for amd64
USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	sbin/storcli
PORTDOCS=	MR_SAS_Unified_StorCLI--00${DISTVERSION}.0000.0000.pdf readme.txt
OPTIONS_DEFINE=	DOCS
BINSRC=		${WRKSRC}/${DISTNAME}/univ_viva_cli_rel/Unified_storcli_all_os

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
DOWNLOAD_URL=	https://docs.broadcom.com/docs/${DISTNAME}${EXTRACT_SUFX}
IGNORE=		you must manually fetch the distribution file \
		(${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, \
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
	${INSTALL_PROGRAM} ${WRKSRC}/storcli64 ${STAGEDIR}${PREFIX}/sbin/storcli

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${BINSRC}/../../MR_SAS_Unified_StorCLI--00${DISTVERSION}.0000.0000.pdf \
		${BINSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
