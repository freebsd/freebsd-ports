# $FreeBSD$

PORTNAME=	otf2bdf
DISTVERSION=	3.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://sofia.nmsu.edu/~mleisher/Software/otf2bdf/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mkinstalldirs
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yasu@utahime.org
COMMENT=	OpenType to BDF converter

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf tar:tgz

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/otf2bdf \
		man/man1/otf2bdf.1.gz

post-extract:
		${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/mkinstalldirs ${WRKSRC}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/otf2bdf

.include <bsd.port.mk>
