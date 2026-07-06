PORTNAME=	hl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	marcel@herrbischoff.com
COMMENT=	JSON and logfmt viewer/processor
WWW=		https://github.com/pamburus/hl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pamburus

PLIST_FILES=	bin/hl \
		etc/bash_completion.d/hl.bash \
		share/fish/completions/hl.fish \
		share/man/man1/hl.1.gz \
		share/zsh/site-functions/_hl

post-build:
	${MKDIR} ${WRKSRC}/autocomplete
	${MKDIR} ${WRKSRC}/man
	${CARGO_TARGET_DIR}/release/hl --man-page > ${WRKSRC}/man/hl.1
	${CARGO_TARGET_DIR}/release/hl --shell-completions bash > ${WRKSRC}/autocomplete/hl.bash
	${CARGO_TARGET_DIR}/release/hl --shell-completions fish > ${WRKSRC}/autocomplete/hl.fish
	${CARGO_TARGET_DIR}/release/hl --shell-completions zsh > ${WRKSRC}/autocomplete/_hl

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/hl.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/autocomplete/hl.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/autocomplete/hl.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/autocomplete/_hl \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
