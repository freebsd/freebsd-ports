# ex:ts=8
# New ports collection makefile for:	nettle
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nettle
PORTVERSION=	2.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.lysator.liu.se/~nisse/archive/:liu \
		ftp://ftp.lysator.liu.se/pub/security/lsh/:liu
MASTER_SITE_SUBDIR=	${PORTNAME}/:DEFAULT

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A low-level cryptographic library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	M4="/usr/bin/m4 -g"
CONFIGURE_ARGS=	--enable-shared
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

DOCS=		NEWS README TODO nettle.html nettle.pdf
EXAMPLES=	examples/*.c examples/*.h

INFO=		nettle

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
