# New ports collection makefile for:    ttt
# Date created:         22 September 1998
# Whom:                 Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ttt
PORTVERSION=	1.4
CATEGORIES=	net tk82
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=     kjc@csl.sony.co.jp

# the tcl/tk LIB_DEPENDS has to match that of ports/x11-toolkits/blt.
LIB_DEPENDS=	BLT24.2:${PORTSDIR}/x11-toolkits/blt \
		tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

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
