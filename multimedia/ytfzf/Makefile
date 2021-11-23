PORTNAME=	ytfzf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Find and watch YouTube videos from the terminal

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl \
		fzf>=0:textproc/fzf \
		jq:textproc/jq \
		mpv:multimedia/mpv \
		notify-send:devel/libnotify \
		shuf:sysutils/shuf \
		ueberzug:graphics/py-ueberzug@${PY_FLAVOR} \
		yt-dlp:www/yt-dlp

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pystardust
PYTHON_NO_DEPENDS=	yes

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	USAGE.md conf.sh
PORTEXAMPLES=	conf.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/USAGE.md ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/conf.sh ${STAGEDIR}${EXAMPLESDIR}
	${RLN} ${STAGEDIR}${EXAMPLESDIR}/conf.sh ${STAGEDIR}${DOCSDIR}/conf.sh

.include <bsd.port.mk>
