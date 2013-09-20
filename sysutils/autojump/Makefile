# Created by: Neeraj Verma <neeraj.verma.ports@vermatech.com>
# $FreeBSD$

PORTNAME=	autojump
PORTVERSION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/joelthelion/autojump/ \
		http://www.vermatech.com/distfiles/
DISTNAME=	autojump_v${PORTVERSION}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	neeraj.verma.ports@vermatech.com
COMMENT=	Autojump is a tool that acts as a complement to cd

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USE_PYTHON_RUN=	YES

NO_BUILD=	YES

SUB_FILES+=	pkg-install

PLIST_FILES=	bin/autojump \
		bin/jumpapplet \
		share/autojump/autojump.bash \
		share/autojump/autojump.zsh \
		share/autojump/icon.png
MAN1=		autojump.1

OPTIONS_DEFINE=		ZSH
OPTIONS_DEFAULT=	ZSH

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZSH}
RUN_DEPENDS+=	${LOCALBASE}/bin/zsh:${PORTSDIR}/shells/zsh
PLIST_FILES+=	 share/zsh/site-functions/_j
.endif

PLIST_DIRS=	share/autojump

post-patch:
	@${REINPLACE_CMD} 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/autojump
	@${REINPLACE_CMD} -e 's|/usr$$|${PREFIX}|' -e 's|/usr/local|${PREFIX}|' -e 's|/bin/bash|${PREFIX}/bin/bash|' ${WRKSRC}/install.sh
	@${REINPLACE_CMD} -e 's|/usr$$|${PREFIX}|' -e 's|/usr/local|${PREFIX}|' -e 's|/bin/zsh|${PREFIX}/bin/zsh|' ${WRKSRC}/install.zsh

do-install:
.if ${PORT_OPTIONS:MZSH}
	@(cd ${INSTALL_WRKSRC} && ${SETENV} PREFIX=${PREFIX} ./install.zsh )
.else
	@(cd ${INSTALL_WRKSRC} && ${SETENV} PREFIX=${PREFIX} ./install.sh )
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
