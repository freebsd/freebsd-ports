# New ports collection makefile for:    ttt
# Date created:         22 September 1998
# Whom:                 Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ttt
PORTVERSION=	1.8.2
PORTREVISION=	3
CATEGORIES=	net tk ipv6
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tele Traffic Tapper, a network traffic monitoring tool

LIB_DEPENDS=	BLT24:${PORTSDIR}/x11-toolkits/blt

USE_TK=	84+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER} \
		--with-tk=${LOCALBASE}/lib/tk${TK_VER}
INSTALL_TARGET=	install install-man
MAN1=		ttt.1 tttprobe.1 tttview.1

post-configure:
	${REINPLACE_CMD} 's|^CFLAGS *=.*|CFLAGS=${CFLAGS}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
