PORTNAME=	sas3ircu
PORTVERSION=	17.00.00.00
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTNAME=	SAS3IRCU_P16

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SAS-3 Integrated RAID Configuration Utility

# Converted from RESTRICTED
LICENSE=	BROADCOM
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	May not be redistributed. Must accept license to download.
LICENSE_PERMS=	none

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Binaries only available for i386 and amd64 from LSI

USES=	zip

WRKSRC=	${WRKDIR}/${DISTNAME}

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
PLIST_FILES=	sbin/sas3ircu
PORTDOCS=	IRCU_MPT_GEN3_Phase16.0-17.00.00.00.pdf \
		README_SAS3IRCU_P16.txt

LSI_SITES=	https://docs.broadcom.com/docs/
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_rel/${PORTNAME}/${PORTNAME}_${OPSYS:tl}_${ARCH:tl}_rel/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/IRCU_MPT_GEN3_Phase16.0-${PORTVERSION}.pdf \
		${WRKSRC}/README_SAS3IRCU_P16.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
