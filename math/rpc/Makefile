# ex:ts=8
# New ports collection makefile for:	rpc
# Date created:			Mar 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpc
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/rpc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-screen RPN calculator program

BUILD_DEPENDS=	${LOCALBASE}/lib/libccm.so:${PORTSDIR}/math/ccmath
RUN_DEPENDS=	${LOCALBASE}/lib/libccm.so:${PORTSDIR}/math/ccmath

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual ${DOCSDIR}
.endif

.include <bsd.port.mk>
