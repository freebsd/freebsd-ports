PORTNAME=	pidgin-skypeweb
PORTVERSION=	1.7
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-im

MAINTAINER=	sepulkarium45@yahoo.com
COMMENT=	Plugin to use Skype chat from Pidgin(without Skype running)
WWW=		https://github.com/EionRobb/skype4pidgin/tree/master/skypeweb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl3.txt

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		cmake dos2unix gettext-runtime gnome localbase:ldflags \
		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_PROJECT=	skype4pidgin
USE_GNOME=	glib20
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	gpl3.txt theme

WRKSRC_SUBDIR=	skypeweb

.include <bsd.port.mk>
