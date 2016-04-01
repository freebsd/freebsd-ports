# Created by: Andrey Akhmichin <sepulkarium45@yahoo.com>
# $FreeBSD$

PORTNAME=	pidgin-skypeweb
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	net-im

MAINTAINER=	sepulkarium45@yahoo.com
COMMENT=	Plugin to use Skype chat from Pidgin(without Skype running)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl3.txt

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_PROJECT=	skype4pidgin

USES=		cmake dos2unix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

DOS2UNIX_FILES=	gpl3.txt \
		libskypeweb.c \
		skypeweb_connection.c \
		skypeweb_contacts.c \
		skypeweb_login.c \
		skypeweb_messages.c \
		skypeweb_util.c \
		skypeweb_util.h \
		theme

CONFLICTS_INSTALL=	pidgin-skype-*
WRKSRC_SUBDIR=	skypeweb

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/emotes/skype
	${INSTALL_DATA} ${WRKSRC}/theme ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/emotes/skype

.include <bsd.port.mk>
