# New ports collection makefile for:    yodl
# Date created:         22 Oct 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yodl
PORTVERSION=	1.31.18
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/ \
					http://www.foad.org/zsh/zsh/ \
					http://www.zsh.org/pub/GPL/ \
					http://mirrors.sunsite.dk/ \
					http://www.math.technion.ac.il/pub/zsh/GPL/ \
					http://litterbug.lut.ac.uk/zsh/ \
					http://ftp.rge.com/pub/shells/zsh/GPL/ \
					http://ftp.dmz.digex.net/pub/packages/ \
					http://linux.sarang.net/ftp/mirror/system/shell/zsh/GPL/

MAINTAINER=	dburr@FreeBSD.org
COMMENT=	An easy to use but powerful document formatting/preparation language

BUILD_DEPENDS=	latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips
RUN_DEPENDS=	latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKEFILE=		GNUmakefile

MAN1=		yodl.1 \
		striproff.1 \
		yodlconverters.1
MAN7=		yodlmacros.7 \
		yodlmanpage.7

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/out/striproff ${PREFIX}/bin

.include <bsd.port.mk>
