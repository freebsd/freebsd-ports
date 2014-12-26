# Created by: Anton Hryciuk <gnixua@gmail.com>
# $FreeBSD$

PORTNAME=	pidgin-audacious-remote
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://pidginaudacious.sourceforge.net/files/ \
		ftp://ftp.lissyara.su/users/gx_ua/distfiles/

MAINTAINER=	gnixua@gmail.com
COMMENT=	Pidgin-Audacious-Remote is a plug-in for Pidgin 2

BUILD_DEPENDS=	audacious>=2.2:${PORTSDIR}/multimedia/audacious \
		pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		libtool pkgconfig tar:bzip2

BROKEN=		Does not work with audacious 3.5 or later
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-01-26

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
