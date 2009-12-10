# New ports collection makefile for:	iksemel
# Date created:			24 April 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	iksemel
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	rhaamo@gruik.at
COMMENT=	XML parser library mainly designed for Jabber applications

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

INFO=	iksemel

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|@setfilename iksemel|@setfilename iksemel.info|' \
	    ${WRKSRC}/doc/iksemel.texi
	@${REINPLACE_CMD} -e 's|pkgconfigdir=$$(libdir)/pkgconfig|pkgconfigdir=$${prefix}/libdata/pkgconfig|' \
	    ${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
