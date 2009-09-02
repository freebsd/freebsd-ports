# New ports collection makefile for:	najitool
# Date created:				18 May 2005
# Whom:					NECDET COKYAZICI <cokyazici@yahoo.co.uk>
#
# $FreeBSD$
#

PORTNAME=	najitool
PORTVERSION=	0.8.1
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool that generates, converts, and filters files

BUILD_DEPENDS=	${LOCALBASE}/lib/libnaji.a:${PORTSDIR}/devel/libnaji

MAKEFILE=	makefile

DISTVERSIONSUFFIX=	.src

post-patch:
	${REINPLACE_CMD} -e 's|cflags =|cflags = -I${LOCALBASE}/include|; s|libnaji.a|${LOCALBASE}/lib/libnaji.a|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/najitool ${PREFIX}/bin

.include <bsd.port.mk>
