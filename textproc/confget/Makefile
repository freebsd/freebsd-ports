# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	confget
PORTVERSION=	1.05
CATEGORIES=	textproc
MASTER_SITES=	http://devel.ringlet.net/textproc/confget/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

LICENSE=	BSD

OPTIONS_DEFINE=	EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

MAKE_ENV=	CFLAGS_CONF=-DHAVE_FGETLN
USES=		gmake

PLIST_FILES=	bin/confget \
		man/man1/confget.1.gz
PORTEXAMPLES=	t1.ini t2.ini

EXAMPLES_MAKE_ENV=	EXAMPLESDIR=${EXAMPLESDIR}
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MPCRE}
MAKE_ENV+=	PCRE_CFLAGS="" PCRE_LIBS=""
.endif

post-patch:
.if !${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e '/^install:/ s| install-examples||' ${WRKSRC}/Makefile
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/confget

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
