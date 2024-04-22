PORTNAME=	aamath
DISTVERSION=	0.3
PORTREVISION=	5
CATEGORIES=	math textproc
MASTER_SITES=	http://fuse.superglue.se/${PORTNAME}/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Renders ASCII art from mathematical expressions
WWW=		http://fuse.superglue.se/aamath/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase ncurses readline
MAKE_ARGS=	LIBS="-lreadline -lncurses"
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/aamath \
		share/man/man1/aamath.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
