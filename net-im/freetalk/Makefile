# Created by: Oleg Ginzburg  (olevole@olevole.ru)
# $FreeBSD$

PORTNAME=	freetalk
PORTVERSION=	4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU console based Jabber client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth \
		libguile-2.2.so:lang/guile2 \
		libgc-threaded.so:devel/boehm-gc-threaded

USES=		autoreconf gettext-runtime gnome localbase makeinfo pkgconfig \
		readline
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GNUFreetalk

INFO=		freetalk

post-patch:
	@${REINPLACE_CMD} -e 's,guile-2\.0,guile-2.2,' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
