PORTNAME=	par
PORTVERSION=	1.53.0
PKGNAMESUFFIX=	_format
CATEGORIES=	textproc
MASTER_SITES=	http://www.nicemice.net/par/
DISTNAME=	Par-${PORTVERSION}

MAINTAINER=	markm@FreeBSD.org
COMMENT=	Paragraph reformatter for email

CONFLICTS=	quake-par

ALL_TARGET=	#
PLIST_FILES=	bin/par \
		man/man1/par.1.gz

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
