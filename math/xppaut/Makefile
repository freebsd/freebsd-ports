# New ports collection makefile for:	xppaut
# Date created:		3 September 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	xppaut
PORTVERSION=	5.91
CATEGORIES=	math graphics
MASTER_SITES=	http://www.math.pitt.edu/~bard/bardware/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	stephen@math.missouri.edu
COMMENT=	Graphical tool for solving differential equations, etc

MAN1=		xppaut.1
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
MAKE_ARGS=	CC="${CC}"

WRKSRC=		${WRKDIR}

post-build:
	${CHMOD} a+r ${WRKSRC}/xppaut.1

pre-configure:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|# PORTDOCS||" ${WRKSRC}/Makefile
.endif

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e "s|gcc|${CC}|" Makefile libI77/Makefile cvodesrc/Makefile mkavi/Makefile)

.include <bsd.port.mk>
