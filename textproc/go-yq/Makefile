# Created by: Pavel Timofeev <timp87@gmail.com>

PORTNAME=	go-yq
PORTVERSION=	4.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	timp87@gmail.com
COMMENT=	Portable commandline YAML processor written in go

LICENSE=	MIT

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mikefarah
GH_PROJECT=	yq

GH_TUPLE=	\
		elliotchance:orderedmap:v1.4.0:elliotchance_orderedmap/vendor/github.com/elliotchance/orderedmap \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		goccy:go-yaml:v1.8.9:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		golang:sys:c4fcb01b228e:golang_sys/vendor/golang.org/x/sys \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jinzhu:copier:v0.2.8:jinzhu_copier/vendor/github.com/jinzhu/copier \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		op:go-logging:b2cb9fa56473:op_go_logging/vendor/gopkg.in/op/go-logging.v1 \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		timtadh:data-structures:v0.5.3:timtadh_data_structures/vendor/github.com/timtadh/data-structures \
		timtadh:lexmachine:v0.2.2:timtadh_lexmachine/vendor/github.com/timtadh/lexmachine

CONFLICTS_INSTALL=	yq

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${GH_PROJECT}

PLIST_FILES=	bin/${GH_PROJECT}

.include <bsd.port.mk>
