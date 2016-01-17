# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	unrtf
PORTVERSION=	0.21.5
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Converter from RTF to several formats, including HTML and LaTeX

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CPE_VENDOR=	unrtf_project

PLIST_FILES=	bin/unrtf \
		%%DATADIR%%/SYMBOL.charmap \
		%%DATADIR%%/html.conf \
		%%DATADIR%%/latex.conf \
		%%DATADIR%%/rtf.conf \
		%%DATADIR%%/text.conf \
		%%DATADIR%%/troff_mm.conf \
		%%DATADIR%%/vt.conf \
		man/man1/unrtf.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

post-patch:
	@${FIND} -X ${WRKSRC} -type f -and -name "*.[1h]" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|/usr/local/lib/unrtf/|${DATADIR}/|g'
	@${REINPLACE_CMD} -e '/^attr_get_param/,/^}/s/return;/return NULL;/' \
		${WRKSRC}/src/attr.c

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>
