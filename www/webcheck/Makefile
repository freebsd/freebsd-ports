# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	webcheck
PORTVERSION=	1.10.3
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://arthurdejong.org/webcheck/

MAINTAINER=	reed@reedmedia.net
COMMENT=	View structure of a web site, get a list of problems like broken links

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:2.7 shebangfix
SHEBANG_FILES=	webcheck.py
NO_BUILD=	yes
NO_ARCH=	yes

# what about fancytooltips?

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/favicon.ico ${STAGEDIR}${DATADIR}
.for d in parsers parsers/html plugins schemes
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/*.py ${STAGEDIR}${DATADIR}/${d}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/fancytooltips
	${INSTALL_DATA} ${WRKSRC}/fancytooltips/* ${STAGEDIR}${DATADIR}/fancytooltips
	${INSTALL_SCRIPT} ${WRKSRC}/webcheck.py ${STAGEDIR}${DATADIR}
	${LN} -sf ../${DATADIR_REL}/webcheck.py ${STAGEDIR}${PREFIX}/bin
	cd ${STAGEDIR}${DATADIR}; ${PYTHON_CMD} -m compileall .
	cd ${STAGEDIR}${DATADIR}; ${PYTHON_CMD} -O -m compileall .
	${INSTALL_MAN} ${WRKSRC}/webcheck.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
