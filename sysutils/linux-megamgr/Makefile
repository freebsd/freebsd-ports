# Ports collection makefile for:  linux-megamgr
# Date created:			  Tue, Sep 5th, 2006
# Whom:				  Patrick M. Hausen (pmh@hausen.com)
#
# $FreeBSD$
#

PORTNAME=		linux-megamgr
PORTVERSION=		5.20
CATEGORIES=		sysutils linux
MASTER_SITES=		http://www.lsi.com/DistributionSystem/AssetDocument/files/support/rsa/utilities/megamgr/
DISTNAME=		ut_linux_mgr_5.20

MAINTAINER=		pmh@hausen.com
COMMENT=		LSI MegaRAID controller management utility

BROKEN=			fails to fetch

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
RESTRICTED=		Redistribution prohibited, see: http://www.lsi.com/cm/License.do
ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		yes
SUB_FILES=		megamgr.sh

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/megamgr.bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/megamgr.sh ${PREFIX}/sbin/megamgr
	${INSTALL_PROGRAM} ${WRKSRC}/megamgr.bin ${PREFIX}/libexec

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${DISTNAME}.txt ${DOCSDIR}/readme.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
IGNORE=			needs at least FreeBSD 6.1 and amr_linux.ko
.endif

.include <bsd.port.post.mk>
