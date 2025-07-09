PORTNAME=	hydroxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.29
PORTREVISION=	10
CATEGORIES=	mail

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Open-source ProtonMail CardDAV, IMAP and SMTP bridge
WWW=		https://github.com/emersion/hydroxide

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
GH_TUPLE=	ProtonMail:go-crypto:v1.0.0:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		cloudflare:circl:v1.3.7:cloudflare_circl/vendor/github.com/cloudflare/circl \
		emersion:go-bcrypt:6e724a1baa63:emersion_go_bcrypt/vendor/github.com/emersion/go-bcrypt \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-mbox:v1.0.3:emersion_go_mbox/vendor/github.com/emersion/go-mbox \
		emersion:go-message:v0.18.1:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:e73c9f7bad43:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.21.1:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-vcard:8fda7d206ec9:emersion_go_vcard/vendor/github.com/emersion/go-vcard \
		emersion:go-webdav:v0.5.0:emersion_go_webdav/vendor/github.com/emersion/go-webdav \
		golang:crypto:v0.22.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.19.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.19.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w"
SUB_LIST=	USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
