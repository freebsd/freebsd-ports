PORTNAME=	imapfilter
PORTVERSION=	2.7.5
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	IMAP mail filtering utility

LICENSE=	MIT

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		cpe lua ssl

CPE_VENDOR=	imapfilter_project

CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	lefcha

PORTDOCS=	LICENSE NEWS README
MAKE_ARGS=	PREFIX=${PREFIX} \
		MYCFLAGS="${CPPFLAGS}" \
		MYLDFLAGS="${LDFLAGS}" \
		BINDIR=${PREFIX}/bin \
		SHAREDIR=${DATADIR} \
		MANDIR=${MANPREFIX}/man \
		LIBLUA=-llua-${LUA_VER}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|-ldl ||' ${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/imapfilter
	@${MKDIR} ${STAGEDIR}/${DATADIR} ${STAGEDIR}/${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} config.lua extend.lua \
			${STAGEDIR}/${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
