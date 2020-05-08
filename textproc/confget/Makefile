# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	confget
PORTVERSION=	2.3.4
DISTVERSIONPREFIX=	release-
CATEGORIES=	textproc
MASTER_SITES=	https://gitlab.com/confget/confget/-/archive/release/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

LICENSE=	BSD2CLAUSE

USES=		gmake

MAKE_ENV=	CFLAGS_CONF=-DHAVE_FGETLN
TEST_TARGET=	test

PLIST_FILES=	bin/confget \
		share/man/man1/confget.1.gz
PORTEXAMPLES=	t1.ini t2.ini

OPTIONS_DEFINE=	EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MAKE_ENV_OFF=	PCRE_CFLAGS="" PCRE_LIBS=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/confget ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/confget.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/t/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
