# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	fq
PORTVERSION=	0.0.7
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool, language, and decoders for inspecting binary data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	wader
GH_TUPLE=	\
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:4e6760a101f9:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		itchyny:timefmt-go:v0.1.3:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		wader:gojq:574a3e400098:wader_gojq/vendor/github.com/wader/gojq \
		wader:readline:692d84ca36e2:wader_readline/vendor/github.com/wader/readline

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
