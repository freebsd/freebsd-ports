# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pidgin-bs
PORTVERSION=	1.3.0
PORTREVISION=	10
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/bot-sentry/${PORTVERSION}
DISTNAME=	bot-sentry-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pidgin plugin to prevent instant message spam

LICENSE=	GPLv3

LIB_DEPENDS=	libpurple.so:net-im/libpurple
RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
USES=		gettext gmake gnome libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
USE_LDCONFIG=	${PREFIX}/lib/pidgin

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
