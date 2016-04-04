# $FreeBSD$

PORTNAME=	ansiweather
PORTVERSION=	1.07
CATEGORIES=	misc

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Shell script for displaying the current weather in your terminal

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	jq:textproc/jq \
		curl:ftp/curl \
		bash:shells/bash \
		gprintf:sysutils/coreutils

USE_GITHUB=	yes
GH_ACCOUNT=	fcambus

NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/ansiweather ${STAGEDIR}${PREFIX}/bin/ansiweather
	${INSTALL_DATA} ${WRKSRC}/ansiweather.plugin.zsh ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ansiweatherrc.example ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
