# New ports collection makefile for:   eps
# Date created:                 21 Jul 2005
# Whom:				ismail@enderunix.org
#
# $FreeBSD$
#

PORTNAME=	eps
PORTVERSION=	1.5
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/eps/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	EPS is a Email Parsing System

USE_REINPLACE=	yes

PORTDOCS=	howto

MAKE_ENV+=	DEFS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC \?=|' \
			  -e 's|^DEFS =|DEFS \?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libeps.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
