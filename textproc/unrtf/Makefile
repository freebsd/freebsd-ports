# New ports collection makefile for:	unrtf
# Date created:		26 March 2002
# Whom:			Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	unrtf
PORTVERSION=	0.21.1
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A converter from RTF to several formats, including HTML and LaTeX

USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

MAN1=		unrtf.1
PLIST_FILES=	bin/unrtf \
		%%DATADIR%%/SYMBOL.charmap \
		%%DATADIR%%/html.conf \
		%%DATADIR%%/latex.conf \
		%%DATADIR%%/rtf.conf \
		%%DATADIR%%/text.conf \
		%%DATADIR%%/vt.conf
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

post-patch:
	@${FIND} -X ${WRKSRC} -type f -and -name "*.[1h]" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|/usr/local/lib/unrtf/|${DATADIR}/|g'

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>
