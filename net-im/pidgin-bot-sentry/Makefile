PORTNAME=	pidgin-bot-sentry
PORTVERSION=	1.3.0
PORTREVISION=	15
CATEGORIES=	net-im
MASTER_SITES=	SF/pidgin-bs/bot-sentry/${PORTVERSION}
DISTNAME=	bot-sentry-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pidgin plugin to prevent instant message spam
WWW=		https://sourceforge.net/projects/pidgin-bs/

LICENSE=	GPLv3

LIB_DEPENDS=	libpurple.so:net-im/libpurple
RUN_DEPENDS=	pidgin:net-im/pidgin

USES=		gettext gmake gnome libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
