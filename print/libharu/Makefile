# ex:ts=8
# Ports collection makefile for:	libharu
# Date created:			Jun 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libharu
PORTVERSION=	2.1.0
CATEGORIES=	print
MASTER_SITES=	http://libharu.org/files/

MAINTAINER=	kimelto@gmail.com
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
