# Created by: Daniel Austin <freebsd-ports@dan.me.uk>
# $FreeBSD$

PORTNAME=	sas2ircu
PORTVERSION=	16.00.00.00
CATEGORIES=	sysutils
MASTER_SITES=	#http://www.lsi.com/downloads/Public/Host%20Bus%20Adapters/Host%20Bus%20Adapters%20Common%20Files/SAS_SATA_6G_P16/
DISTNAME=	SAS2IRCU_P16

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Tool for basic management of mps(4) based LSI RAID controllers

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		zip
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Binaries only available for i386 and amd64 from LSI

RESTRICTED=	May not be redistributed. Must accept license to download.

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
DISTFILE_INSTRUCTIONS=\n\
Due to licensing restrictions, certain files must be fetched manually.\n\
Please visit the following URL and accept the license agreement.\n\n\
http://www.lsi.com/downloads/Public/Host%%20Bus%%20Adapters/Host%%20Bus%%20Adapters%%20Common%%20Files/SAS_SATA_6G_P16/SAS2IRCU_P16.zip\n\n\
After the download has completed, please place ${DISTNAME}${EXTRACT_SUFX} in\n\
${DISTDIR}, then restart the build.\n\n
.endif

.if defined(DISTFILE_INSTRUCTIONS)
.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.else
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1;
.endif
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme_Release_Notes_SAS2IRCU_Phase_16.00.00.00.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/SAS2Flash_ReferenceGuide.pdf ${STAGEDIR}${DOCSDIR}
.endif
.if ${ARCH} == "amd64"
	${INSTALL_PROGRAM} ${WRKSRC}/sas2ircu_freebsd_amd64_rel/sas2ircu ${STAGEDIR}${PREFIX}/sbin
.else
	${INSTALL_PROGRAM} ${WRKSRC}/sas2ircu_freebsd_i386_rel/sas2ircu ${STAGEDIR}${PREFIX}/sbin
.endif

.include <bsd.port.post.mk>
