# New ports collection makefile for:    lsof
# Version required:     3.87
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.22 1998/06/09 16:09:47 obrien Exp $
#

DISTNAME=	lsof_4.35_W
PKGNAME=	lsof-4.35
CATEGORIES=	sysutils
MASTER_SITES=	ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/  \
		ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
		ftp://ftp.auscert.org.au/pub/mirrors/vic.cc.purdue.edu/lsof/  \
		ftp://ftp.web.ad.jp/pub/UNIX/tools/lsof/  \
		ftp://ftp.sunet.se/pub/unix/admin/lsof/

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/${SRCBALL_NAME}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd
MAN1=		lsof.1

SRCBALL_NAME=	${DISTNAME:S/_W$//}

post-extract:
	@( cd ${WRKDIR} ; \
	EXPMD5=`/usr/bin/grep MD5 README.${SRCBALL_NAME} | sed 's/^[ ]*//'` ; \
	CALCMD5=`${MD5} ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		echo "Expected and calculated MD5 signatures don't agree." ; \
		echo "($$EXPMD5 != $$CALCMD5)" ; \
		exit 1 ; \
	fi ; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS:S/z//} ${SRCBALL_NAME}.tar \
	)
	@( cd ${WRKSRC} ; echo "y" | ./Inventory || exit 1 )


do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m 2755 -g kmem ${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.man ${PREFIX}/man/man1/lsof.1
	@${MKDIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@/bin/chmod 0444 ${PREFIX}/share/lsof/00*


.include <bsd.port.mk>
