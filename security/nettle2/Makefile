# ex:ts=8
# New ports collection makefile for:	nettle
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nettle
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A low-level cryptographic library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--enable-shared
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

DOCS=		NEWS README TODO nettle.html
EXAMPLES=	examples/*.c examples/*.h

INFO=		nettle

post-extract:
	@${RM} -f ${WRKSRC}/nettle.info*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
