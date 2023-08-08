PORTNAME=	murex
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.5110
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
		eliukblau:pixterm:v1.3.1:eliukblau_pixterm/vendor/github.com/eliukblau/pixterm \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:image:v0.5.0:golang_image/vendor/golang.org/x/image \
		golang:sys:v0.8.0:golang_sys/vendor/golang.org/x/sys \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		lmorg:apachelogs:e5f3eae677ad:lmorg_apachelogs/vendor/github.com/lmorg/apachelogs \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.16:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:permbits:39d7c581d2ee:phayes_permbits/vendor/github.com/phayes/permbits \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.8.2:stretchr_testify/vendor/github.com/stretchr/testify

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
