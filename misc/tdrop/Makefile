PORTNAME=	tdrop
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Glorified WM-Independent Dropdown Creator
WWW=		https://github.com/noctuid/tdrop

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		coreutils>=9.1:sysutils/coreutils \
		gawk:lang/gawk \
		tmux:sysutils/tmux \
		xdotool:x11/xdotool \
		xprop:x11/xprop \
		xrandr:x11/xrandr \
		xwininfo:x11/xwininfo

USE_GITHUB=	yes
GH_ACCOUNT=	noctuid

NO_BUILD=	yes

PLIST_FILES=	bin/tdrop \
		share/man/man1/tdrop.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tdrop ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tdrop.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
