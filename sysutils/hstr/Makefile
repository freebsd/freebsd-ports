PORTNAME=	hstr
DISTVERSION=	3.1
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

PLIST_FILES=	bin/hh \
		bin/hstr \
		share/bash-completion/completions/hstr \
		share/man/man1/hstr.1.gz

.include <bsd.port.mk>
