# New ports collection makefile for:    hmmah
# Date created:         Jun 6, 2001
# Whom:                 dwcjr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hmmah
PORTVERSION=	1.0
CATEGORIES=	shells
MASTER_SITES=	http://dyeske.netrush.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com

NO_BUILD=

WRKSRC=		${WRKDIR}/${PORTNAME}
do-install:
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/dot.bash_prompt ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/dot.ksh_prompt ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/dot.tcsh_prompt ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/dot.zsh_prompt ${PREFIX}/share/doc/${PORTNAME}

post-install:
	@${ECHO_MSG} "-------------------------------------------------------------------------------"
	@${ECHO_MSG} "Copy the dot.(shell)_prompt file to ~/.(shell)_prompt and then "
	@${ECHO_MSG} "run it via your shell start up file such as .bashrc, .tcshrc, .zshrc, or .kshrc"
	@${ECHO_MSG} "-------------------------------------------------------------------------------"

.include <bsd.port.mk>
