PORTNAME=	sqstat
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://samm.kiev.ua/sqstat/ \
		SF/sqstat/sqstat/sqstat-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script which allows to look through active squid users connections

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

USES=		php
USE_PHP=	pcre session
NO_BUILD=	yes
NO_ARCH=	yes

SQSTATDIR?=	share/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	SQSTATDIR=${SQSTATDIR}

PLIST_FILES=	${SQSTATDIR}/arrow.gif ${SQSTATDIR}/sqstat.class.php \
		${SQSTATDIR}/sqstat.css ${SQSTATDIR}/sqstat.php \
		${SQSTATDIR}/zhabascript.js \
		${SQSTATDIR}/config.inc.php.defaults
PORTDOCS=	CHANGES FAQ README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SQSTATDIR}
.for f in ${PLIST_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f:T} ${STAGEDIR}${PREFIX}/${SQSTATDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
