PORTNAME=	gitwatch
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Bash script to watch a file or folder and commit changes to a git repo
WWW=		https://github.com/gitwatch/gitwatch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		git:devel/git@lite \
		inotifywait:sysutils/inotify-tools

USES=		shebangfix
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}.sh

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
