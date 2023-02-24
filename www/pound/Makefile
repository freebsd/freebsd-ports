PORTNAME=	pound
PORTVERSION=	4.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www net

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	HTTP/HTTPS reverse-proxy and load-balancer
WWW=		https://github.com/graygnuorg/pound

LICENSE=	GPLv3+

USES=		autoreconf cpe gmake ssl
CPE_VENDOR=	apsis
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tcmalloc --disable-hoard
USE_GITHUB=	yes
GH_ACCOUNT=	graygnuorg
USE_RC_SUBR=	${PORTNAME}
TEST_TARGET=	check

SUB_FILES=	${PORTNAME}.cfg
SUB_LIST=	NAME=${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog.apsis NEWS README.md THANKS

OPTIONS_DEFINE=	DOCS DSAPARAM PCRE
OPTIONS_DEFAULT=PCRE
DSAPARAM_DESC=	Generate DH parameters without using "safe" primes

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_USES=	localbase
PCRE_CONFIGURE_ENABLE=	pcreposix

post-patch-DSAPARAM-on:
	@${REINPLACE_CMD} -e '/openssl dhparam/s,-5,-dsaparam,' \
		${WRKSRC}/src/Makefile.am

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
