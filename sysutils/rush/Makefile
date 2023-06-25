PORTNAME=	rush
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-parallelization-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line tool for executing jobs in parallel
WWW=		https://github.com/shenwei356/rush

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	shenwei356
GH_TUPLE=	\
		cznic:mathutil:297441e03548:cznic_mathutil/vendor/github.com/cznic/mathutil \
		cznic:sortutil:f5f958428db8:cznic_sortutil/vendor/github.com/cznic/sortutil \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		elastic:go-windows:v1.0.1:elastic_go_windows/vendor/github.com/elastic/go-windows \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		golang:crypto:30dcbda58838:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:fbc7d0a398ab:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		klauspost:compress:v1.15.12:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		palantir:stacktrace:78658fd2d177:palantir_stacktrace/vendor/github.com/palantir/stacktrace \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		remyoudompheng:bigfft:eec4a21b6bb0:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		schollz:progressbar:v3.9.0:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		shenwei356:go-logging:c6b9702d88ba:shenwei356_go_logging/vendor/github.com/shenwei356/go-logging \
		shenwei356:natsort:600d539c017d:shenwei356_natsort/vendor/github.com/shenwei356/natsort \
		shenwei356:util:v0.5.1:shenwei356_util/vendor/github.com/shenwei356/util \
		shenwei356:xopen:v0.3.1:shenwei356_xopen/vendor/github.com/shenwei356/xopen \
		shirou:gopsutil:v3.21.11:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		spf13:cobra:v1.5.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tklauser:go-sysconf:v0.3.10:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.4.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		ulikunitz:xz:v0.5.11:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		yusufpapurcu:wmi:v1.2.2:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
