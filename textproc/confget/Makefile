# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	confget
PORTVERSION=	2.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://devel.ringlet.net/files/textproc/confget/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

MAKE_ENV=	CFLAGS_CONF=-DHAVE_FGETLN
TEST_TARGET=	test
USES=		gmake tar:xz

PLIST_FILES=	bin/confget \
		man/man1/confget.1.gz
PORTEXAMPLES=	t1.ini t2.ini

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MAKE_ENV_OFF=	PCRE_CFLAGS="" PCRE_LIBS=""

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/confget ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/confget.1 ${STAGEDIR}${PREFIX}/man/man1/
	cd ${WRKSRC}/t/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
