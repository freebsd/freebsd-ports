# Created by: Patrick M. Hausen (pmh@hausen.com)
# $FreeBSD$

PORTNAME=		linux-megamgr
PORTVERSION=		5.20
CATEGORIES=		sysutils linux
MASTER_SITES=		http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/
DISTNAME=		ut_linux_mgr_5.20

MAINTAINER=		ports@FreeBSD.org
COMMENT=		LSI MegaRAID controller management utility

BROKEN=			Does not fetch

NO_WRKSUBDIR=		yes
USES=			dos2unix
USE_ZIP=		yes
RESTRICTED=		Redistribution seems to be prohibited
ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		yes
SUB_FILES=		megamgr.sh
DOS2UNIX_FILES=		ut_linux_mgr_5.20.txt

NO_STAGE=	yes
do-build:
	${CHMOD} 755 ${WRKSRC}/megamgr.bin
	${BRANDELF} -t Linux ${WRKSRC}/megamgr.bin
	${REINPLACE_CMD} -E -e 's,[[:blank:]]+$$,,' ${WRKSRC}/ut_linux_mgr_5.20.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/megamgr.sh ${PREFIX}/sbin/megamgr
	${INSTALL_PROGRAM} ${WRKSRC}/megamgr.bin ${PREFIX}/libexec

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${DISTNAME}.txt ${DOCSDIR}/readme.txt
.endif

pre-fetch:
	#
	# You may need to accept LSI's End-User License Agreement
	# before downloading. If the automatic fetching fails,
	# please, paste the following URL into your browser:
	#
	#	${MASTER_SITES}${_DISTFILES}
	#
	# and save the downloaded file into ${DISTDIR}/
	#

.include <bsd.port.mk>
