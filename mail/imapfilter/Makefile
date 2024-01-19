PORTNAME=	imapfilter
PORTVERSION=	2.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	IMAP mail filtering utility
WWW=		https://github.com/lefcha/imapfilter

LICENSE=	MIT

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		cpe localbase:ldflags lua ssl
CPE_VENDOR=	imapfilter_project
USE_GITHUB=	yes
GH_ACCOUNT=	lefcha

MAKE_ARGS=	PREFIX=${PREFIX} \
		MYCFLAGS="${CPPFLAGS}" \
		MYLDFLAGS="${LDFLAGS}" \
		BINDIR=${PREFIX}/bin \
		SHAREDIR=${DATADIR} \
		MANDIR=${MANPREFIX}/man \
		LIBLUA=-llua-${LUA_VER}

CPPFLAGS+=	-I${LUA_INCDIR}

PORTDOCS=	LICENSE NEWS README

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} 's|-ldl ||' ${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/imapfilter

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}/${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}/${DATADIR} ${STAGEDIR}/${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} config.lua extend.lua \
			${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
