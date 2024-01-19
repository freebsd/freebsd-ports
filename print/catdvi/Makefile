PORTNAME=	catdvi
PORTVERSION=	0.14
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI to text/plain translator
WWW=		https://catdvi.sourceforge.net/

LICENSE=	GPLv2

USES=		gmake tex
USE_TEX=	latex
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/catdvi share/man/man1/catdvi.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdvi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdvi.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
