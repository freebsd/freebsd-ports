# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	libsexy
PORTVERSION=	0.1.11
PORTREVISION=	6
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexy/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Extension widgets for GTK+

LICENSE=	LGPL21

LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig gettext
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack lthack gtk20 libxml2
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|g_strncasecmp|g_ascii_strncasecmp|' \
		${WRKSRC}/libsexy/sexy-spell-entry.c

.include <bsd.port.mk>
