PORTNAME=	rush
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2-9
DISTVERSIONSUFFIX=	-ga800565
PORTREVISION=	3
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-parallelization-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line tool for executing jobs in parallel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	shenwei356
GH_TUPLE=	\
		cznic:sortutil:f5f958428db8:cznic_sortutil/vendor/github.com/cznic/sortutil \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		klauspost:compress:v1.12.3:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.13:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		shenwei356:bpool:f9e0ee4:shenwei356_bpool/vendor/github.com/shenwei356/bpool \
		shenwei356:go-logging:c6b9702:shenwei356_go_logging/vendor/github.com/shenwei356/go-logging \
		shenwei356:natsort:600d539:shenwei356_natsort/vendor/github.com/shenwei356/natsort \
		shenwei356:util:v0.3.0:shenwei356_util/vendor/github.com/shenwei356/util \
		shenwei356:xopen:f4f16dd:shenwei356_xopen/vendor/github.com/shenwei356/xopen \
		shirou:gopsutil:v3.21.4:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tklauser:go-sysconf:v0.3.6:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
