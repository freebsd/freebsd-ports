# Created by: trasz
# $FreeBSD$

PORTNAME=	iksemel
PORTVERSION=	1.4
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	rhaamo@gruik.at
COMMENT=	XML parser library mainly designed for Jabber applications

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

USES=		libtool makeinfo pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	--add-missing --copy --force
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

INFO=	iksemel

post-patch:
	@${REINPLACE_CMD} -e 's|@setfilename iksemel|@setfilename iksemel.info|' \
	    ${WRKSRC}/doc/iksemel.texi

.include <bsd.port.mk>
