# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-translate-cli
PORTVERSION=	0.8.19
DISTVERSIONPREFIX=	v
#PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google Translate to serve as a command line tool

LICENSE=	BW
LICENSE_NAME=	Beerware
LICENSE_TEXT=	http://www.sax.de/~joerg/beerware-license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	gawk:lang/gawk
RUN_DEPENDS=	bash:shells/bash \
		gawk:lang/gawk
TEST_DEPENDS=	gawk:lang/gawk

ALL_TARGET=	build

FRIBIDI_RUN_DEPENDS=	fribidi:converters/fribidi

GH_ACCOUNT=	soimort
GH_PROJECT=	translate-shell

OPTIONS_DEFINE=	DOCS FRIBIDI READLINE TEXT2SPEECH

PLIST_FILES=	bin/trans man/man1/trans.1.gz

READLINE_RUN_DEPENDS=	rlwrap:devel/rlwrap

TEXT2SPEECH_DESC=	Enable Text-to-Speech functionality via espeak
TEXT2SPEECH_RUN_DEPENDS=	espeak:audio/espeak

USE_GITHUB=	yes

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/trans ${STAGEDIR}${PREFIX}/bin/trans
	${INSTALL_MAN} ${WRKSRC}/man/trans.1 ${STAGEDIR}${MANPREFIX}/man/man1/trans.1

regression-test test: build
	@(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
