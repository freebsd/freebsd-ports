# New ports collection makefile for:    ttt
# Version required:     1.1
# Date created:         9 July 1998
# Whom:                 Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $Id: Makefile,v 1.4 1998/02/21 22:38:10 fenner Exp $
#

DISTNAME=       ttt-1.1
CATEGORIES=	net tk80
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=     kjc@csl.sony.co.jp

# the tcl/tk LIB_DEPENDS has to match that of ports/x11/blt.
LIB_DEPENDS=	BLT\\.2\\.4:${PORTSDIR}/x11/blt \
		tcl80\\.1:${PORTSDIR}/lang/tcl80 \
		tk80\\.1:${PORTSDIR}/x11/tk80

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
