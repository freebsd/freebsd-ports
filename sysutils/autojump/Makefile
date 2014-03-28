# Created by: Neeraj Verma <neeraj.verma.ports@vermatech.com>
# $FreeBSD$

PORTNAME=	autojump
PORTVERSION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/joelthelion/autojump/ \
		http://www.vermatech.com/distfiles/
DISTNAME=	autojump_v${PORTVERSION}

MAINTAINER=	neeraj.verma.ports@vermatech.com
COMMENT=	Tool that acts as a complement to cd

LICENSE=	GPLv3

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USE_PYTHON_RUN=	yes
SUB_FILES=	pkg-install

PLIST_FILES=	bin/autojump \
		bin/jumpapplet \
		man/man1/autojump.1.gz \
		share/autojump/autojump.bash \
		share/autojump/autojump.zsh \
		share/autojump/icon.png
PLIST_DIRS=	share/autojump

OPTIONS_DEFINE=		ZSH
OPTIONS_DEFAULT=	ZSH

ZSH_RUN_DEPENDS=	zsh:${PORTSDIR}/shells/zsh
ZSH_PLIST_FILES=	share/zsh/site-functions/_j

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/#!\/usr\/bin/s|python|env &|' \
		${WRKSRC}/autojump

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${SH} ./install.sh \
		--prefix ${STAGEDIR}${PREFIX})
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/_j \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
.endif

.include <bsd.port.mk>
