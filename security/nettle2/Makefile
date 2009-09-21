# ex:ts=8
# New ports collection makefile for:	nettle2
# Date created:			13 Sep 2009
# Whom:				corky1951@comcast.net
#
# $FreeBSD$
#

PORTNAME=	nettle2
PORTVERSION=	2.0
CATEGORIES=	security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	A low-level cryptographic library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--enable-shared \
		--includedir=${PREFIX}/include/${DISTNAME} \
		--bindir=${PREFIX}/bin/${DISTNAME} \
		--libdir=${PREFIX}/lib/${DISTNAME}

LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

DOCS=		NEWS README TODO nettle.html nettle.pdf
EXAMPLES=	examples/*.c examples/*.h

INFO=		nettle2

post-extract:
	@${MV} ${WRKSRC}/nettle.info ${WRKSRC}/nettle2.info

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
