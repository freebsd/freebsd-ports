# Created by: johs
# $FreeBSD$

PORTNAME=	detachtty
PORTVERSION=	9
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/detachtty/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run interactive programs non-interactively

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}-9
USES=		gmake

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/[ad][te]tachtty
	${INSTALL_MAN} ${WRKSRC}/detachtty.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/detachtty.1 ${STAGEDIR}${MANPREFIX}/man/man1/attachtty.1

.include <bsd.port.mk>
