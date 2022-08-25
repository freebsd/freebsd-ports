PORTNAME=	lurch
PORTVERSION=	4.0.2
PORTREVISION=	1
CATEGORIES=	security net-im net
MASTER_SITES=	https://research.ngportal.com/lurch/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	micadeyeye@gmail.com
COMMENT=	Implement OMEMO encryption in  Pidgin

LICENSE=	GPLv2 
LICENSE_FILE=	${WRKSRC}/COPYING

# explicitly use libpurple and mxml
BUILD_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	liblurch.so:security/liblurch \
		libpurple.so:net-im/libpurple

USES=		cpe gmake gnome libtool pkgconfig
CPE_VENDOR=	maoshin
CPE_PRODUCT=	${PKGNAMEPREFIX}${PORTNAME}
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libotr-prefix=${LOCALBASE}/lib \
		--with-libotr-inc-prefix=${LOCALBASE}/include

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

.include <bsd.port.mk>
