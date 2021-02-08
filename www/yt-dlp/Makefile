# $FreeBSD$

PORTNAME=	yt-dlp
DISTVERSION=	2021.02.04
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line program to download videos from youtube & other platforms

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	pukkandan

NO_ARCH=	yes

POST_PLIST=	fix-plist

post-install: # https://github.com/pukkandan/yt-dlp/issues/59
	@cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} share/doc/youtube_dlc share/man/man1 etc/bash_completion.d etc/fish/completions etc/fish

fix-plist: # https://github.com/pukkandan/yt-dlp/issues/59
	@${REINPLACE_CMD} -e "s|^etc/bash_completion\.d$$|| ; s|^etc/fish/completions$$|| ; s|^share/doc/youtube_dlc$$|| ; s|^share/man/man1$$||" ${TMPPLIST}

.include <bsd.port.mk>
