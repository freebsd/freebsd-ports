PORTNAME=	webcpp
PORTVERSION=	0.8.4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Webcpp/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	chip-set@mail.ru
COMMENT=	Convert your source code to syntax highlighted HTML

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.if defined(WANT_FINAL)
CONFIGURE_ARGS+=	--enable-final
USES=		gmake
.endif

pre-patch:
	${FIND} ${WRKSRC} -name '*.h' | ${XARGS} ${REINPLACE_CMD} \
		's|IO->close()|if(IO) IO->close()|g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS COPYING README TODO docs.html
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
