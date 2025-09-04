PORTNAME=	tunneller
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.6
PORTREVISION=	29
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Expose internal services to be accessed over the internet
WWW=		https://github.com/skx/tunneller

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	skx
GH_TUPLE=	\
		cjbassi:drawille-go:27dc511fe6fd:cjbassi_drawille_go/vendor/github.com/cjbassi/drawille-go \
		eclipse:paho.mqtt.golang:v1.2.0:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		gizak:termui:v3.0.0:gizak_termui/vendor/github.com/gizak/termui/v3 \
		golang:net:afe8014c977f:golang_net/vendor/golang.org/x/net \
		google:subcommands:v1.0.1:google_subcommands/vendor/github.com/google/subcommands \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		nsf:termbox-go:02980233997d:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
