# New ports collection makefile for:   eps
# Date created:                 21 Jul 2005
# Whom:				ismail@enderunix.org
#
# $FreeBSD$
#

PORTNAME=	eps
PORTVERSION=	1.7
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}inter7/${PORTNAME}inter7/${PORTVERSION}

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	EPS is a Email Parsing System

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

PORTDOCS=	howto

MAKE_ENV+=	DEFS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC \?=|' \
			  -e 's|^DEFS =|DEFS \?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libeps.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/eps
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/eps

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
