# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	aamath
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	math textproc
MASTER_SITES=	http://fuse.superglue.se/${PORTNAME}/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Renders ASCII art from mathematical expressions

LICENSE=	GPLv2

USES=		readline

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/aamath man/man1/aamath.1.gz

CFLAGS+=	-I${LOCALBASE}/include

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
