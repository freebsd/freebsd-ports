PORTNAME=	stc
PORTVERSION=	1.5.4
PORTREVISION=	6
CATEGORIES=	net

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Syncthing CLI Tool
WWW=		https://github.com/tenox7/stc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	tenox7
GH_TUPLE=	\
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		go-resty:resty:v2.16.5:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		golang:net:v0.35.0:golang_net/vendor/golang.org/x/net \
		hako:durafmt:5c1018a4e16b:hako_durafmt/vendor/github.com/hako/durafmt

PLIST_FILES=	bin/stc

post-patch:
	@${REINPLACE_CMD} -e 's|"homedir", ""|"homedir", "${LOCALBASE}/etc/syncthing"|' ${WRKSRC}/stc.go

.include <bsd.port.mk>
