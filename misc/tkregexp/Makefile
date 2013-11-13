# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	tkregexp
PORTVERSION=	3.1
CATEGORIES=	misc tk
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/
DISTNAME=	visual_regexp-${PORTVERSION}
EXTRACT_SUFX=	.tcl
EXTRACT_ONLY=	

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Interactive regexp design tool

USES+=		tk
USE_DOS2UNIX=	visual_regexp-${PORTVERSION}.tcl
NO_BUILD=	yes
PLIST_FILES=	bin/tkregexp

WRKSRC=		${WRKDIR}

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e "1s|^\(.*\)|#!${WISH}|; 2d" ${WRKDIR}/visual_regexp-${PORTVERSION}.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/visual_regexp-${PORTVERSION}.tcl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
