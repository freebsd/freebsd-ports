# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termshark
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Terminal UI for tshark, inspired by Wireshark

LICENSE=	MIT

RUN_DEPENDS=	tshark>0:net/tshark

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	gcla
GH_TUPLE=	blang:semver:v3.6.1:semver \
		gcla:gowid:v1.0.0:gowid \
		gcla:deep:v1.0.2:deep \
		pkg:errors:v0.8.1:pkgerrors \
		shibukawa:configdir:e180dbd:configdir \
		sirupsen:logrus:v1.4.1:logrus \
		spf13:viper:v1.3.2:viper \
		fsnotify:fsnotify:v1.4.7:fsnotify \
		go-yaml:yaml:7f97868:go_yaml \
		gdamore:tcell:v1.1.1:tcell \
		gdamore:encoding:v1.0.0:encoding \
		hashicorp:golang-lru:v0.5.1:golanglru \
		hashicorp:hcl:v1.0.0:hcl \
		magiconair:properties:v1.8.0:properties \
		mitchellh:mapstructure:v1.1.2:mapstructure \
		pelletier:go-toml:v1.3.0:gotoml \
		spf13:afero:v1.2.2:afero \
		spf13:cast:v1.3.0:cast \
		spf13:pflag:v1.0.3:pflag \
		spf13:jwalterweatherman:v1.1.0:jwalterweatherman \
		lucasb-eyer:go-colorful:v1.0.2:colorful \
		mattn:go-runewidth:v0.0.4:runewidth \
		mattn:go-isatty:v0.0.7:isatty \
		jessevdk:go-flags:v1.4.0:goflags \
		golang:text:v0.3.0:text

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/blang \
		${GO_WRKDIR_SRC}/github.com/gcla \
		${GO_WRKDIR_SRC}/github.com/pkg \
		${GO_WRKDIR_SRC}/github.com/shibukawa \
		${GO_WRKDIR_SRC}/github.com/sirupsen \
		${GO_WRKDIR_SRC}/github.com/spf13 \
		${GO_WRKDIR_SRC}/github.com/fsnotify \
		${GO_WRKDIR_SRC}/gopkg.in \
		${GO_WRKDIR_SRC}/github.com/go-yaml \
		${GO_WRKDIR_SRC}/github.com/gdamore \
		${GO_WRKDIR_SRC}/github.com/hashicorp \
		${GO_WRKDIR_SRC}/github.com/magiconair \
		${GO_WRKDIR_SRC}/github.com/mitchellh \
		${GO_WRKDIR_SRC}/github.com/pelletier \
		${GO_WRKDIR_SRC}/github.com/fsnotify \
		${GO_WRKDIR_SRC}/github.com/golang \
		${GO_WRKDIR_SRC}/github.com/mattn \
		${GO_WRKDIR_SRC}/github.com/lucasb-eyer \
		${GO_WRKDIR_SRC}/github.com/jessevdk \
		${GO_WRKDIR_SRC}/golang.org/x
	${MV} ${WRKSRC_semver} ${GO_WRKDIR_SRC}/github.com/blang/semver
	${MV} ${WRKSRC_deep} ${GO_WRKDIR_SRC}/github.com/gcla/deep
	${MV} ${WRKSRC_gowid} ${GO_WRKDIR_SRC}/github.com/gcla/gowid
	${MV} ${WRKSRC_pkgerrors} ${GO_WRKDIR_SRC}/github.com/pkg/errors
	${MV} ${WRKSRC_configdir} ${GO_WRKDIR_SRC}/github.com/shibukawa/configdir
	${MV} ${WRKSRC_logrus} ${GO_WRKDIR_SRC}/github.com/sirupsen/logrus
	${MV} ${WRKSRC_viper} ${GO_WRKDIR_SRC}/github.com/spf13/viper
	${MV} ${WRKSRC_fsnotify} ${GO_WRKDIR_SRC}/gopkg.in/fsnotify.v1
	(cd ${GO_WRKDIR_SRC}/github.com/fsnotify && ${LN} -s ../../gopkg.in/fsnotify.v1 fsnotify)
	${MV} ${WRKSRC_go_yaml} ${GO_WRKDIR_SRC}/gopkg.in/yaml.v2
	${MV} ${WRKSRC_encoding} ${GO_WRKDIR_SRC}/github.com/gdamore/encoding
	${MV} ${WRKSRC_tcell} ${GO_WRKDIR_SRC}/github.com/gdamore/tcell
	${MV} ${WRKSRC_golanglru} ${GO_WRKDIR_SRC}/github.com/hashicorp/golang-lru
	${MV} ${WRKSRC_hcl} ${GO_WRKDIR_SRC}/github.com/hashicorp/hcl
	${MV} ${WRKSRC_properties} ${GO_WRKDIR_SRC}/github.com/magiconair/properties
	${MV} ${WRKSRC_mapstructure} ${GO_WRKDIR_SRC}/github.com/mitchellh/mapstructure
	${MV} ${WRKSRC_gotoml} ${GO_WRKDIR_SRC}/github.com/pelletier/go-toml
	${MV} ${WRKSRC_afero} ${GO_WRKDIR_SRC}/github.com/spf13/afero
	${MV} ${WRKSRC_cast} ${GO_WRKDIR_SRC}/github.com/spf13/cast
	${MV} ${WRKSRC_pflag} ${GO_WRKDIR_SRC}/github.com/spf13/pflag
	${MV} ${WRKSRC_jwalterweatherman} ${GO_WRKDIR_SRC}/github.com/spf13/jwalterweatherman
	${MV} ${WRKSRC_colorful} ${GO_WRKDIR_SRC}/github.com/lucasb-eyer/go-colorful
	${MV} ${WRKSRC_runewidth} ${GO_WRKDIR_SRC}/github.com/mattn/go-runewidth
	${MV} ${WRKSRC_isatty} ${GO_WRKDIR_SRC}/github.com/mattn/go-isatty
	${MV} ${WRKSRC_text} ${GO_WRKDIR_SRC}/golang.org/x/text
	${MV} ${WRKSRC_goflags} ${GO_WRKDIR_SRC}/github.com/jessevdk/go-flags
	(cd ${GO_WRKDIR_SRC}/golang.org/x && ${LN} -s ${LOCALBASE}/go/src/cmd/vendor/golang.org/x/sys sys)

.include <bsd.port.mk>
