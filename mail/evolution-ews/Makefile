# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-ews/Makefile 19851 2014-09-08 10:26:54Z gusi $

PORTNAME=	evolution-ews
PORTVERSION=	3.12.6
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange Web Services

BUILD_DEPENDS=	evolution>=3.0.0:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libmspack.so:${PORTSDIR}/archivers/libmspack \
		libical.so:${PORTSDIR}/devel/libical
RUN_DEPENDS=	evolution>=3.0.0:${PORTSDIR}/mail/evolution

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
USE_SQLITE=	3
USE_BDB=	5
USE_OPENLDAP=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

VERSION=	3.12
PLIST_SUB=	VERSION=${VERSION}

.include <bsd.port.mk>
