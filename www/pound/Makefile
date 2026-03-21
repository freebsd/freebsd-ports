PORTNAME=	pound
PORTVERSION=	4.21
CATEGORIES=	www net
MASTER_SITES=	https://github.com/graygnuorg/pound/releases/download/v${PORTVERSION}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	HTTP/HTTPS reverse-proxy and load-balancer
WWW=		https://github.com/graygnuorg/pound \
		https://gray.gnu.org.ua/project/pound

LICENSE=	GPLv3+

TEST_DEPENDS=	p5-IO-FDPass>=0:devel/p5-IO-FDPass \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

USES=		cpe gmake ssl
CPE_VENDOR=	apsis
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tcmalloc --disable-hoard
USE_RC_SUBR=	${PORTNAME}
TEST_TARGET=	check

SUB_FILES=	${PORTNAME}.cfg
SUB_LIST=	NAME=${PORTNAME}

INFO=		${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog ChangeLog.apsis NEWS README THANKS

OPTIONS_DEFINE=	DOCS LUA PCRE
OPTIONS_DEFAULT=PCRE

LUA_USES=		lua # supported versions: 5.3.5 or 5.4
LUA_CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" \
			LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"
LUA_CONFIGURE_OFF=	--disable-lua

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_CONFIGURE_OFF=	--disable-pcre

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
