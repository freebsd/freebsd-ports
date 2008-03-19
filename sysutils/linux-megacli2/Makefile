# Ports collection makefile for:  linux-megacli
# Date created:			  Wed, Nov 29th, 2006
# Whom:				  Ruben van Staveren (ruben@verweg.com)
#
# $FreeBSD$
#

PORTNAME=	megacli
PORTVERSION=	1.01.40
CATEGORIES=	sysutils linux
MASTER_SITES=	http://www.lsi.com/support/downloads/megaraid/miscellaneous/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTVERSION}_Linux_Cli

MAINTAINER=	ruben@verweg.com
COMMENT=	LSI MegaRAID SAS controller management utility

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
RESTRICTED=	Redistribution prohibited, see: http://lsi.com/cm/License.do
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
SUB_FILES=	megacli.sh
SUB_FILES+=	407.status-mfi-raid

# From bsd.linux.rpm.mk
RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio
EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

post-extract:
	cd ${WRKSRC} && \
		${RPM2CPIO} MegaCli-${PORTVERSION}-0.i386.rpm | ${CPIO} -id --quiet

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/opt/MegaRAID/MegaCli/MegaCli

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/megacli.sh ${PREFIX}/sbin/megacli
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKSRC}/407.status-mfi-raid ${PREFIX}/etc/periodic/daily
	${INSTALL_PROGRAM} ${WRKSRC}/opt/MegaRAID/MegaCli/MegaCli ${PREFIX}/libexec

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTVERSION}_Linux_Cli.txt ${DOCSDIR}/readme.txt
	${INSTALL_MAN} ${FILESDIR}/README-status-mfi-raid.txt ${DOCSDIR}/README-status-mfi-raid.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602000
IGNORE=			needs at least FreeBSD 6.2 and mfi_linux.ko
.endif

.include <bsd.port.post.mk>
