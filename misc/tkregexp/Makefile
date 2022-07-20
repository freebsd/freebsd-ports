PORTNAME=	tkregexp
PORTVERSION=	3.1
CATEGORIES=	misc tk
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/
DISTNAME=	visual_regexp-${PORTVERSION}
EXTRACT_SUFX=	.tcl
EXTRACT_ONLY=

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Interactive regexp design tool

USES=		dos2unix tk
DOS2UNIX_FILES=	visual_regexp-${PORTVERSION}.tcl

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/tkregexp

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e "1s|^\(.*\)|#!${WISH}|; 2d" ${WRKSRC}/visual_regexp-${PORTVERSION}.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp-${PORTVERSION}.tcl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
