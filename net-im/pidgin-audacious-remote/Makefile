# Created by: Anton Hryciuk <gnixua@gmail.com>
# $FreeBSD$

PORTNAME=	pidgin-audacious-remote
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://pidginaudacious.sourceforge.net/files/ \
		ftp://ftp.lissyara.su/users/gx_ua/distfiles/
#DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnixua@gmail.com
COMMENT=	Pidgin-Audacious-Remote is a plug-in for Pidgin 2

BUILD_DEPENDS=	audacious>=2.2:${PORTSDIR}/multimedia/audacious \
		pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig
USE_BZIP2=	yes


GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

.include <bsd.port.mk>
