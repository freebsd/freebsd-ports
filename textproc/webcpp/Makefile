PORTNAME=	webcpp
PORTVERSION=	0.8.4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Webcpp/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	chip-set@mail.ru
COMMENT=	Convert source code to syntax-highlighted HTML
WWW=		https://webcpp.sourceforge.net/

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS FINAL

FINAL_DESC=	Size-optimized build (experimental: needs lots of RAM)
FINAL_USES=	gmake
FINAL_CONFIGURE_ON=	--enable-final

pre-patch:
	${FIND} ${WRKSRC} -name '*.h' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|IO->close()|if (IO) &|'

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS COPYING README TODO docs.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
