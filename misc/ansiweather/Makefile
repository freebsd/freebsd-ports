PORTNAME=	ansiweather
PORTVERSION=	1.19.0
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Shell script for displaying the current weather in your terminal
WWW=		https://github.com/fcambus/ansiweather/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jq:textproc/jq \
		curl:ftp/curl \
		bash:shells/bash \
		gprintf:sysutils/coreutils

USE_GITHUB=	yes
GH_ACCOUNT=	fcambus

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ansiweather ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ansiweather.plugin.zsh ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/ansiweather.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ansiweatherrc.example ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
