# Created by: Neeraj Verma <neeraj.verma.ports@vermatech.com>
# $FreeBSD$

PORTNAME=	autojump
PORTVERSION=	13
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vermatech.com/distfiles/
DISTNAME=	autojump_v${PORTVERSION}

MAINTAINER=	neeraj.verma.ports@vermatech.com
COMMENT=	Tool that acts as a complement to cd

BROKEN=		unfetchable

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		python:run shebangfix
NO_BUILD=	yes
SHEBANG_FILES=	autojump jumpapplet
SUB_FILES=	pkg-install
NO_ARCH=	yes

PLIST_FILES=	bin/autojump \
		bin/jumpapplet \
		man/man1/autojump.1.gz \
		share/autojump/autojump.bash \
		share/autojump/autojump.zsh \
		share/autojump/icon.png \
		share/zsh/site-functions/_j

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${SH} ./install.sh \
		--prefix ${STAGEDIR}${PREFIX})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/_j \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
