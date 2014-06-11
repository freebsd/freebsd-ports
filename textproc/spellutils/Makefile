# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	spellutils
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://home.worldonline.dk/byrial/spellutils/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Programs used to isolate some parts or texts before spell-checking

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gettext tar:bzip2
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl

DOCS=		NEWS README
EXAMPLES=	aspell.sl

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
.for FILE in ${EXAMPLES}
	${INSTALL_DATA} ${FILESDIR}/${FILE} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
