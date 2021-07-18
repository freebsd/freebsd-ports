# Created by: Patrice Clement <monsieurp@gentoo.org>

PORTNAME=	hstr
DISTVERSION=	2.3
CATEGORIES=	sysutils

MAINTAINER=	monsieurp@gentoo.org
COMMENT=	Bash and Zsh shell history suggest box

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf ncurses pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	dvorka

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/hh bin/hstr \
		man/man1/hstr.1.gz share/bash-completion/completions/hstr

.include <bsd.port.mk>
