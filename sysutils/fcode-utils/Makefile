# Created by: Piotr Kubaj <pkubaj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fcode-utils
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Utilities to process FCODE, OpenFirmware's byte code

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	openbios

MAKE_ARGS=	CC=${CC}
PLIST_FILES=	bin/detok \
		bin/romheaders \
		bin/toke
PORTDOCS=	detok.html toke.html workbook.css

OPTIONS_DEFINE=	DOCS

do-build:
.for f in detok romheaders toke
	@${DO_MAKE_BUILD} -C ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detok/detok ${WRKSRC}/toke/toke \
		${WRKSRC}/romheaders/romheaders ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/documentation && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
