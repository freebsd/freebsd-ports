# $FreeBSD$

PORTNAME=	bibutils
PORTVERSION=	6.6
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	_src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program set interconverts between various bibliography formats

LICENSE=	GPLv2

USES=		gmake

HAS_CONFIGURE=	yes
TEST_TARGET=	test

BINARIES=	bib2xml bibdiff biblatex2xml copac2xml ebi2xml end2xml endx2xml \
		isi2xml med2xml modsclean nbib2xml ris2xml wordbib2xml xml2ads \
		xml2bib xml2end xml2isi xml2nbib xml2ris xml2wordbib
PLIST_FILES=	${BINARIES:S,^,bin/,}

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} ${BINARIES}

.include <bsd.port.mk>
