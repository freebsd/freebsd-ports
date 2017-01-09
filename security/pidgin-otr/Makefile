# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	4.0.2
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows deniable private conversations using Pidgin

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

# explicitly use libotr.so.5 (see ports/186944)
BUILD_DEPENDS=	pidgin:net-im/pidgin
LIB_DEPENDS=	libotr.so.5:security/libotr \
		libgcrypt.so:security/libgcrypt \
		libpurple.so:net-im/libpurple

USES=		cpe gmake libtool pkgconfig
CPE_VENDOR=	cypherpunks
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
