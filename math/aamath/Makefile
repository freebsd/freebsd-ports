# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	aamath
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	math textproc
MASTER_SITES=	http://fuse.superglue.se/${PORTNAME}/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Renders ASCII art from mathematical expressions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		readline

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/aamath man/man1/aamath.1.gz

CFLAGS+=	-I${LOCALBASE}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
