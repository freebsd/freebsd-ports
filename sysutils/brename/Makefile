PORTNAME=	brename
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0-5
DISTVERSIONSUFFIX=	-g2e8b7d0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for batch renaming files/directories via regular expressions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	shenwei356
GH_TUPLE=	\
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		golang:sys:0cec03c:golang_sys/vendor/golang.org/x/sys \
		klauspost:compress:b5e9484:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:e899416:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		shenwei356:breader:d28a754:shenwei356_breader/vendor/github.com/shenwei356/breader \
		shenwei356:go-logging:c6b9702:shenwei356_go_logging/vendor/github.com/shenwei356/go-logging \
		shenwei356:natsort:600d539:shenwei356_natsort/vendor/github.com/shenwei356/natsort \
		shenwei356:util:3c0b696:shenwei356_util/vendor/github.com/shenwei356/util \
		shenwei356:xopen:f4f16dd:shenwei356_xopen/vendor/github.com/shenwei356/xopen \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		twotwotwo:sorts:bf5c1f2:twotwotwo_sorts//vendor/github.com/twotwotwo/sorts

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
