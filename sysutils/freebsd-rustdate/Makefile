PORTNAME=	freebsd-rustdate
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://rustdate.over-yonder.net/dl/ \
		https://distfiles.over-yonder.net/freebsd-rustdate/
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265703
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Faster freebsd-update replacement
WWW=		https://rustdate.over-yonder.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl tar:xz

PLIST_FILES=	bin/freebsd-rustdate \
		etc/bash_completion.d/freebsd-rustdate.bash \
		share/fish/completions/freebsd-rustdate.fish \
		share/zsh/site-functions/_freebsd-rustdate

post-install:
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/freebsd-rustdate complete -s bash > \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/freebsd-rustdate.bash
	${STAGEDIR}${PREFIX}/bin/freebsd-rustdate complete -s fish > \
		${STAGEDIR}${PREFIX}/share/fish/completions/freebsd-rustdate.fish
	${STAGEDIR}${PREFIX}/bin/freebsd-rustdate complete -s zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_freebsd-rustdate

.include <bsd.port.mk>
