PORTNAME=	murex
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.1000
PORTREVISION=	10
CATEGORIES=	shells

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Shell designed for greater commandline productivity and safer shell scripts
WWW=		https://murex.rocks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	lmorg
GH_TUPLE=	Knetic:govaluate:v3.0.0:knetic_govaluate/vendor/github.com/Knetic/govaluate \
		abesto:sexp:v0.0.1:abesto_sexp/vendor/github.com/abesto/sexp \
		boombuler:barcode:v1.0.1:boombuler_barcode/vendor/github.com/boombuler/barcode \
		creack:pty:v1.1.18:creack_pty/vendor/github.com/creack/pty \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eliukblau:pixterm:v1.3.1:eliukblau_pixterm/vendor/github.com/eliukblau/pixterm \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:image:v0.10.0:golang_image/vendor/golang.org/x/image \
		golang:mod:v0.8.0:golang_mod/vendor/golang.org/x/mod \
		golang:sys:v0.8.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.6.0:golang_tools/vendor/golang.org/x/tools \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lmorg:apachelogs:e5f3eae677ad:lmorg_apachelogs/vendor/github.com/lmorg/apachelogs \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lukechampine:uint128:v1.2.0:lukechampine_uint128/vendor/lukechampine.com/uint128 \
		mattn:go-isatty:v0.0.17:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.16:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:permbits:39d7c581d2ee:phayes_permbits/vendor/github.com/phayes/permbits \
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.8.2:stretchr_testify/vendor/github.com/stretchr/testify
GL_TUPLE=	cznic:cc:03159e8e41eec8d08c1e502bfc46868b9a03aa57:cznic_cc/vendor/modernc.org/cc/v3 \
		cznic:ccgo:0641811a3b4e1b829e42b48fa6cf751b3a681ed5:cznic_ccgo/vendor/modernc.org/ccgo/v3 \
		cznic:libc:8014ff305ac880ad7b60918a18992e59405eb7f3:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:b13e5b5643328f15fd2fcedc85f647f0d8f9180f:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:2014ace98d6392882e3d171baf4b76b21a0e7813:cznic_memory/vendor/modernc.org/memory \
		cznic:opt:6b647abadf922391a4527f3a4fa1817eff08b7cd:cznic_opt/vendor/modernc.org/opt \
		cznic:sqlite:a16e15fbb42ad21e3665c92e257b4ec4600f2f15:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:strutil:bba0c72b66bb9ced2dfd2ee521b7f16b2cbb39fa:cznic_strutil/vendor/modernc.org/strutil \
		cznic:token:a1b392cca155ddafa8e1e45905db0dfe27cd4714:cznic_token/vendor/modernc.org/token

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.mx \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
