# Created by: trasz
# $FreeBSD$

PORTNAME=	iksemel
PORTVERSION=	1.4
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML parser library mainly designed for Jabber applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		autoreconf libtool makeinfo pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		iksemel

post-patch:
	@${REINPLACE_CMD} -e 's|@setfilename iksemel|@setfilename iksemel.info|' \
	    ${WRKSRC}/doc/iksemel.texi

.include <bsd.port.mk>
