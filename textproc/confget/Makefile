# New ports collection makefile for:	confget
# Date created:		18 March 2009
# Whom:			Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	confget
PORTVERSION=	1.03
CATEGORIES=	textproc
MASTER_SITES=	http://devel.ringlet.net/textproc/confget/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

OPTIONS=	PCRE "Regular expression support" on

MAKE_ENV=	CFLAGS_CONF=-DHAVE_FGETLN
USE_GMAKE=	yes

MAN1=		confget.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/confget
PORTEXAMPLES=	t1.ini t2.ini

.if !defined(NOPORTEXAMPLES)
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}
.endif

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre.1:${PORTSDIR}/devel/pcre
.else
MAKE_ENV+=	PCRE_CFLAGS="" PCRE_LIBS=""
.endif

post-patch:
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e '/^install:/ s| install-examples||' ${WRKSRC}/Makefile
.endif

regression-test test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
