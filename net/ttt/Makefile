# New ports collection makefile for:    ttt
# Version required:     0.4.1
# Date created:         18 November 1997
# Whom:                 Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.3 1997/11/22 11:57:46 itojun Exp $
#

DISTNAME=       ttt-0.4.1
CATEGORIES=	net tk41
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=     itojun@itojun.org

# the tcl/tk LIB_DEPENDS has to match that of ports/x11/blt.
LIB_DEPENDS=	BLT:${PORTSDIR}/x11/blt \
		tcl75:${PORTSDIR}/lang/tcl75 \
		tk41\\.1:${PORTSDIR}/x11/tk41

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
