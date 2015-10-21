# $FreeBSD$

PORTNAME=	sas3ircu
PORTVERSION=	11.00.00.00
CATEGORIES=	sysutils
MASTER_SITES=	
DISTNAME=	SAS3IRCU_P10

LSI_SITES=	http://docs.avagotech.com/docs-and-downloads/host-bus-adapters/host-bus-adapters-common-files/sas_sata_12g_p10/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	SAS-3 Integrated RAID Configuration Utility

WRKSRC=	${WRKDIR}/${DISTNAME}

USES=	zip
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Binaries only available for i386 and amd64 from LSI

RESTRICTED=	May not be redistributed. Must accept license to download.

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	sbin/sas3ircu
PORTDOCS=	IRCU_MPT_GEN3_Phase10.0-11.00.00.00.pdf \
		README_SAS3IRCU_P10.txt

DISTFILE_INSTRUCTIONS=	\n\
Due to licensing restrictions, certain files must be fetched manually.\n\
Please visit the following URL and accept the license agreement.\n\n\
${LSI_SITES}${DISTNAME}${EXTRACT_SUFX}\n\n\
After the download has completed, please place ${DISTNAME}${EXTRACT_SUFX} in\n\
${DISTDIR}, then restart the build.\n\n

.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.endif

.include <bsd.port.pre.mk>

.if ! exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}" ; exit 1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_${OPSYS:tl}_${ARCH:tl}_rel/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/IRCU_MPT_GEN3_Phase10.0-${PORTVERSION}.pdf \
		${WRKSRC}/README_SAS3IRCU_P10.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
