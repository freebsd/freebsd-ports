PORTNAME=	ab-av1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AV1 re-encoding using ffmpeg, svt-av1 & vmaf
WWW=		https://github.com/alexheretic/ab-av1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	alexheretic
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install:
.for _shell in bash fish zsh
	@${ECHO_MSG} "Generating ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}"
	@${CARGO_CARGO_RUN} run ${CARGO_BUILD_ARGS} -- print-completions ${_shell} \
		>${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}
.endfor

.include <bsd.port.mk>
