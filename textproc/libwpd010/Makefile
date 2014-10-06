# Created by: reed@pugetsoundtechnology.com
# $FreeBSD$

PORTNAME=	libwpd
PORTVERSION=	0.10.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Tools for importing and exporting WordPerfect(tm) documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	librevenge-0.0.so:${PORTSDIR}/textproc/librevenge

USES=		pathfix libtool:keepla tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	libgsf
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--without-docs
PLIST_SUB=	MAJVER=${PORTVERSION:R}

.include <bsd.port.mk>
