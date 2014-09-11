# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	confget
PORTVERSION=	1.05
CATEGORIES=	textproc
MASTER_SITES=	http://devel.ringlet.net/textproc/confget/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

MAKE_ENV=	CFLAGS_CONF=-DHAVE_FGETLN
USES=		gmake

PLIST_FILES=	bin/confget \
		man/man1/confget.1.gz
PORTEXAMPLES=	t1.ini t2.ini

PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_MAKE_ENV_OFF=	PCRE_CFLAGS="" PCRE_LIBS=""

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/confget ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/confget.1 ${STAGEDIR}${PREFIX}/man/man1/
	cd ${WRKSRC}/t/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
