# New ports collection makefile for:    lsof
# Version required:     3.75
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/11/11 19:42:44 obrien Exp $
#

DISTNAME=	lsof_3.81_W
PKGNAME=	lsof-3.81
CATEGORIES=	sysutils
MASTER_SITES=	ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/  \
		ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
		ftp://ftp.auscert.org.au/pub/mirrors/vic.cc.purdue.edu/lsof/  \
		ftp://ftp.web.ad.jp/pub/UNIX/tools/lsof/  \
		ftp://ftp.sunet.se/pub/unix/admin/lsof

MAINTAINER=     obrien@cs.ucdavis.edu

WRKSRC=		${WRKDIR}/${SRCBALL_NAME}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd

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


post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/lsof.1
.endif

.include <bsd.port.mk>
