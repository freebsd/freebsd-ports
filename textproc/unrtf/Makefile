# New ports collection makefile for:	unrtf
# Date created:		26 March 2002
# Whom:			Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	unrtf
PORTVERSION=	0.21.0
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A converter from RTF to several formats, including HTML and LaTeX

USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

MAN1=		unrtf.1
PLIST_FILES=	bin/unrtf \
		%%DATADIR%%/charmaps/SYMBOL \
		%%DATADIR%%/outputs/html \
		%%DATADIR%%/outputs/latex \
		%%DATADIR%%/outputs/rtf \
		%%DATADIR%%/outputs/text \
		%%DATADIR%%/outputs/vt
PLIST_DIRS=	%%DATADIR%%/outputs \
		%%DATADIR%%/charmaps \
		%%DATADIR%%

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -liconv

post-patch:
	@${FIND} ${WRKSRC} -name "*.[1h]" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/usr/local/lib/unrtf/|${DATADIR}/|g'

.include <bsd.port.mk>
