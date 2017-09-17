# $FreeBSD$

PORTNAME=	bibutils
PORTVERSION=	5.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Program set interconverts between various bibliography formats

LICENSE=	GPLv2

USES=	gmake tar:tgz

USE_HARDENING=	pie:off

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

HAS_CONFIGURE=	yes

test: all
	cd ${WRKSRC}/test && ${MAKE_CMD} all test

BINARIES=	bib2xml biblatex2xml copac2xml ebi2xml end2xml endx2xml \
		isi2xml med2xml modsclean ris2xml wordbib2xml xml2ads \
		xml2bib xml2end xml2isi xml2ris xml2wordbib

PLIST_FILES=	${BINARIES:S,^,bin/,}

.include <bsd.port.mk>
