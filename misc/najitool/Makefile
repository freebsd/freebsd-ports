# New ports collection makefile for:	najitool
# Date created:				18 May 2005
# Whom:					NECDET COKYAZICI <cokyazici@yahoo.co.uk>
#
# $FreeBSD$
#

PORTNAME=	najitool
PORTVERSION=	0.5.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	najitool

MAINTAINER=	cokyazici@yahoo.co.uk
COMMENT=	A tool that generates, converts, and filters files

BUILD_DEPENDS=	${LOCALBASE}/lib/libnaji.a:${PORTSDIR}/devel/libnaji

USE_REINPLACE=	yes

MAKEFILE=	makefile

DISTVERSIONSUFFIX=	.src

post-patch:
	${REINPLACE_CMD} -e 's|cflags =|cflags = -I${LOCALBASE}/include|; s|libnaji.a|${LOCALBASE}/lib/libnaji.a|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/najitool ${PREFIX}/bin

.include <bsd.port.mk>
