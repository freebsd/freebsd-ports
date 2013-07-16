# Created by: trasz
# $FreeBSD$

PORTNAME=	iksemel
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	rhaamo@gruik.at
COMMENT=	XML parser library mainly designed for Jabber applications

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		pkgconfig

INFO=	iksemel

post-patch:
	@${REINPLACE_CMD} -e 's|@setfilename iksemel|@setfilename iksemel.info|' \
	    ${WRKSRC}/doc/iksemel.texi
	@${REINPLACE_CMD} -e 's|pkgconfigdir=$$(libdir)/pkgconfig|pkgconfigdir=$${prefix}/libdata/pkgconfig|' \
	    ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
