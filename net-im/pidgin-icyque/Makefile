# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pidgin-icyque
DISTVERSION=	g20181222
CATEGORIES=	net-im

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Pidgin plugin for ICQ/WIM protocol

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

PLIST_FILES=	lib/purple-2/libicyque.so

USES=		gmake localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_PROJECT=	icyque
GH_TAGNAME=	c70f9f8
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}

USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
