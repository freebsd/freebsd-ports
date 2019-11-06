# Created by: erik@smluc.org
# $FreeBSD$

PORTNAME=	permute
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://atlas.kennesaw.edu/~rbentley/

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Generate all permutations of lines from stdin

BROKEN=		unfetchable

PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
