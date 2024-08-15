PORTNAME=	confget
PORTVERSION=	5.1.2
CATEGORIES=	textproc
MASTER_SITES=	https://devel.ringlet.net/files/textproc/confget/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files
WWW=		https://devel.ringlet.net/textproc/confget/ \
		https://gitlab.com/confget/confget

LICENSE=	BSD2CLAUSE

USES=		gmake tar:xz

MAKE_ENV=	CFLAGS_CONF=-DHAVE_FGETLN
TEST_TARGET=	test

PLIST_FILES=	bin/confget \
		share/man/man1/confget.1.gz
PORTEXAMPLES=	t1.ini t2.ini

OPTIONS_DEFINE=	EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_MAKE_ENV_OFF=	PCRE_CFLAGS="" PCRE_LIBS=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/confget ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/confget.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/t/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
