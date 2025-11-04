PORTNAME=	tth
DISTVERSION=	4.16
CATEGORIES=	textproc
MASTER_SITES=	http://silas.psfc.mit.edu/tth/tars/
DISTNAME=	tthC

MAINTAINER=	alven@FreeBSD.org
COMMENT=	TeX to HTML translator
WWW=		http://silas.psfc.mit.edu/tth/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	bash:shells/bash \
		ppmtogif:graphics/netpbm

USES=		ghostscript:run shebangfix tar:tgz

SHEBANG_FILES=	${WRKSRC}/tthprep

WRKSRC=		${WRKDIR}/tthgold

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		tth.c tthprep *.html *.tex

do-build:
.for c in tth tthrfcat tthsplit
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${c} ${c}.c
.endfor

do-install:
.for p in tth tthrfcat tthsplit
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin
.endfor
.for s in latex2gif tthprep
	${INSTALL_SCRIPT}  ${WRKSRC}/${s} ${STAGEDIR}${PREFIX}/bin
.endfor

	${MKDIR} ${STAGEDIR}${DATADIR}/styles
	${INSTALL_DATA} ${WRKSRC}/*.sty ${STAGEDIR}${DATADIR}/styles
	cd ${WRKSRC} && ${COPYTREE_SHARE} babel ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.html *.tex ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
