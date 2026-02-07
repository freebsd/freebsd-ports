PORTNAME=	ytfzf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Find and watch YouTube videos from the terminal
WWW=		https://github.com/pystardust/ytfzf

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

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.5.gz

PORTEXAMPLES=	conf.sh

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.5 ${STAGEDIR}${PREFIX}/share/man/man5

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/conf.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
