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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*

post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
