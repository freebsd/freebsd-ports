# Ports collection makefile for:  linux-megacli
# Date created:			  Wed, Nov 29th, 2006
# Whom:				  Ruben van Staveren (ruben@verweg.com)
#
# $FreeBSD$
#

PORTNAME=	megacli
PORTVERSION=	2.00.15
CATEGORIES=	sysutils linux
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTVERSION}_Linux_MegaCLI

MAINTAINER=	ruben@verweg.com
COMMENT=	LSI MegaRAID SAS controller management utility

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
RESTRICTED=	Redistribution prohibited, see: http://lsi.com/cm/License.do
NO_PACKAGE=	Redistribution prohibited, see: http://lsi.com/cm/License.do
DOWNLOAD_URL=	http://www.lsi.com/cm/License.do?url=http://www.lsi.com/DistributionSystem/AssetDocument/support/downloads/megaraid/miscellaneous/linux/2.00.15_Linux_MegaCLI.zip&prodName=MegaRAID%%20SAS%%208708EM2&subType=Miscellaneous&locale=EN
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
SUB_FILES=	megacli.sh
SUB_FILES+=	407.status-mfi-raid
SUB_FILES+=	mfi_tty_log

# From bsd.linux.rpm.mk
RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio
EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) && !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) #{
DISTFILE_INSTRUCTIONS=\n\
${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.\n\n
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})#{
DISTFILE_INSTRUCTIONS+=Please access\n\n\
\ \ \ \ ${DOWNLOAD_URL}\n\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"MegaCLI - Linux ${PORTVERSION}\".\n\n
.endif#}
DISTFILE_INSTRUCTIONS+=Please place the downloaded file(s) in ${DISTDIR}.\n\n
.endif#}

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

post-extract:
	cd ${WRKSRC} && \
		${UNZIP_CMD} MegaCliLin.zip && \
		${RPM2CPIO} MegaCli-${PORTVERSION}-1.i386.rpm | ${CPIO} -id --quiet

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/opt/MegaRAID/MegaCli/MegaCli

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/megacli.sh ${PREFIX}/sbin/megacli
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKSRC}/407.status-mfi-raid ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKSRC}/mfi_tty_log ${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/opt/MegaRAID/MegaCli/MegaCli ${PREFIX}/libexec

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTVERSION}_Linux_Cli.txt ${DOCSDIR}/readme.txt
	${INSTALL_MAN} ${FILESDIR}/README-status-mfi-raid.txt ${DOCSDIR}/README-status-mfi-raid.txt
.endif
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 602000
IGNORE=			needs at least FreeBSD 6.2 and mfi_linux.ko
.endif

.include <bsd.port.post.mk>
