PORTNAME=	hstr
DISTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	monsieurp@gentoo.org
COMMENT=	Bash and Zsh shell history suggest box
WWW=		https://github.com/dvorka/hstr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf ncurses pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	dvorka

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/hh bin/hstr \
		share/man/man1/hstr.1.gz share/bash-completion/completions/hstr

.include <bsd.port.mk>
