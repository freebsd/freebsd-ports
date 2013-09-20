# $FreeBSD$

PORTNAME=	bibutils
PORTVERSION=	5.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/

DISTNAME=	${PORTNAME}_${PORTVERSION}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Program set interconverts between various bibliography formats

LICENSE=	GPLv2

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

NO_STAGE=	yes
do-configure:
	@cd ${WRKSRC} && ./configure --install-dir ${PREFIX}/bin

test: all
	cd ${WRKSRC}/test && ${GMAKE} all test

BINARIES=	bib2xml biblatex2xml copac2xml ebi2xml end2xml endx2xml \
		isi2xml med2xml modsclean ris2xml wordbib2xml xml2ads \
		xml2bib xml2end xml2isi xml2ris xml2wordbib

.for binary in ${BINARIES}
PLIST_FILES+=	bin/${binary}
.endfor

.include <bsd.port.mk>
