# New ports collection makefile for:    ttt
# Version required:     1.2
# Date created:         15 July 1998
# Whom:                 Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $Id: Makefile,v 1.6 1998/07/15 05:51:57 kjc Exp $
#

DISTNAME=       ttt-1.2
CATEGORIES=	net tk80
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=     kjc@csl.sony.co.jp

# the tcl/tk LIB_DEPENDS has to match that of ports/x11-toolkits/blt.
LIB_DEPENDS=	BLT\\.2\\.4:${PORTSDIR}/x11-toolkits/blt \
		tcl80\\.1:${PORTSDIR}/lang/tcl80 \
		tk80\\.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install-man
MAN1=		ttt.1 tttprobe.1 tttview.1

post-install:
	@if [ ! -c /dev/bpf1 ]; then \
	  ${ECHO} "*********************************************************";\
	  ${ECHO} "*                      W a r n i n g                    *";\
	  ${ECHO} "* TTT needs Berkeley packet filter (bpf).               *";\
	  ${ECHO} "* To use TTT, your kernel must be rebuilt with bpf, and *";\
	  ${ECHO} "* make bpf devices on /dev directory.                   *";\
	  ${ECHO} "*********************************************************";\
	fi

.include <bsd.port.mk>
