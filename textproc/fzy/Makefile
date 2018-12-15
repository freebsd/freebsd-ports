# $FreeBSD$

PORTNAME=	fzy
DISTVERSION=	1.0
CATEGORIES=	textproc

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Interactive fuzzy text selector for the terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	jhawthorn

PLIST_FILES=	bin/fzy man/man1/fzy.1.gz

OPTIONS_DEFINE=		TMUX DVTM
OPTIONS_DEFAULT=	TMUX
TMUX_DESC=	Install fzy-tmux
DVTM_DESC=	Install fzy-dvtm

TMUX_PLIST_FILES=	bin/fzy-tmux
DVTM_PLIST_FILES=	bin/fzy-dvtm

post-extract:
	${CP} ${WRKSRC}/src/config.def.h ${WRKSRC}/config.h

post-patch:
	@${REINPLACE_CMD} \
		-e 's, -g,,g' \
		-e 's, -O3,,g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fzy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fzy.1 ${STAGEDIR}${MANPREFIX}/man/man1/

do-install-TMUX-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/fzy-tmux ${STAGEDIR}${PREFIX}/bin

do-install-DVTM-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/fzy-dvtm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
