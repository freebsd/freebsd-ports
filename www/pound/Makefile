PORTNAME=	pound
PORTVERSION=	4.17
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

OPTIONS_DEFINE=	DOCS DSAPARAM PCRE
OPTIONS_DEFAULT=PCRE

DSAPARAM_DESC=	Generate DH parameters without using "safe" primes

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_CONFIGURE_OFF=	--disable-pcre

post-patch-DSAPARAM-on:
	@${REINPLACE_CMD} -e '/openssl dhparam/s,-5,-dsaparam,' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
