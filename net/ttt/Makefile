# New ports collection makefile for:    ttt
# Version required:     0.4.1
# Date created:         18 November 1997
# Whom:                 Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id$
#

DISTNAME=       ttt-0.4.1
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=     itojun@itojun.org

LIB_DEPENDS=	BLT:${PORTSDIR}/x11/blt

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
