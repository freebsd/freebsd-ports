# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-ews/Makefile 19735 2014-06-09 09:37:57Z gusi $

PORTNAME=	evolution-ews
PORTVERSION=	3.12.3
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

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_SQLITE=	3
USE_BDB=	5
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

VERSION=	3.12
PLIST_SUB=	VERSION=${VERSION}

.include <bsd.port.mk>
