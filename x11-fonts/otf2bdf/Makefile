PORTNAME=	otf2bdf
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://sofia.nmsu.edu/~mleisher/Software/otf2bdf/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mkinstalldirs
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenType to BDF converter
WWW=		http://sofia.nmsu.edu/~mleisher/Software/otf2bdf/

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf pkgconfig tar:tgz

GNU_CONFIGURE=	yes

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/otf2bdf \
		share/man/man1/otf2bdf.1.gz

post-extract:
		${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/mkinstalldirs ${WRKSRC}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/otf2bdf

.include <bsd.port.mk>
