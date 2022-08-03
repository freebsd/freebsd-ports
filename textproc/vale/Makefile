PORTNAME=	vale
PORTVERSION=	2.20.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line tool that brings editorial style guide to life

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	errata-ai
GH_TUPLE=	\
		atomicgo:cursor:v0.0.1:atomicgo_cursor/vendor/github.com/atomicgo/cursor \
		d5:tengo:v2.10.0:d5_tengo_v2/vendor/github.com/d5/tengo/v2 \
		dsnet:compress:f66993602bf5:dsnet_compress/vendor/github.com/dsnet/compress \
		errata-ai:ini:v1.63.0:errata_ai_ini/vendor/github.com/errata-ai/ini \
		errata-ai:regexp2:v1.7.0:errata_ai_regexp2/vendor/github.com/errata-ai/regexp2 \
		frankban:quicktest:v1.14.3:frankban_quicktest/vendor/github.com/frankban/quicktest \
		go-check:check:788fd7840127:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:97ac67df715c:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		gookit:color:v1.4.2:gookit_color/vendor/github.com/gookit/color \
		jdkato:prose:v1.2.1:jdkato_prose/vendor/github.com/jdkato/prose \
		jdkato:regexp:v0.1.0:jdkato_regexp/vendor/github.com/jdkato/regexp \
		jdkato:titlecase:0158ddd948b8:jdkato_titlecase/vendor/github.com/jdkato/titlecase \
		karrick:godirwalk:v1.16.1:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mholt:archiver:v3.1.1:mholt_archiver/vendor/github.com/mholt/archiver \
		mitchellh:mapstructure:v1.4.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		montanaflynn:stats:v0.6.3:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		neurosnap:sentences:v1.0.6:neurosnap_sentences/vendor/gopkg.in/neurosnap/sentences.v1 \
		niklasfasching:go-org:v1.6.5:niklasfasching_go_org/vendor/github.com/niklasfasching/go-org \
		nwaples:rardecode:v1.1.0:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		otiai10:copy:v1.7.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pierrec:lz4:v2.6.1:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pterm:pterm:v0.12.33:pterm_pterm/vendor/github.com/pterm/pterm \
		remeh:sizedwaitgroup:v1.0.0:remeh_sizedwaitgroup/vendor/github.com/remeh/sizedwaitgroup \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		shogo82148:go-shuffle:27e6095f230d:shogo82148_go_shuffle/vendor/github.com/shogo82148/go-shuffle \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz \
		xo:terminfo:ca9a967f8778:xo_terminfo/vendor/github.com/xo/terminfo \
		yuin:goldmark:v1.4.12:yuin_goldmark/vendor/github.com/yuin/goldmark

GO_TARGET=	./cmd/vale

PLIST_FILES=	bin/vale

.include <bsd.port.mk>
