PORTNAME=	catdvi
PORTVERSION=	0.14
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI to text/plain translator

LICENSE=	GPLv2

USE_TEX=	latex
USES=		gmake
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/catdvi man/man1/catdvi.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdvi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdvi.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
