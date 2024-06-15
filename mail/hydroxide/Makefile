PORTNAME=	hydroxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.28
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Open-source ProtonMail CardDAV, IMAP and SMTP bridge
WWW=		https://github.com/emersion/hydroxide

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	emersion

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/hydroxide
GH_TUPLE=	ProtonMail:go-crypto:5aa5874ade95:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		cloudflare:circl:v1.3.3:cloudflare_circl/vendor/github.com/cloudflare/circl \
		emersion:go-bcrypt:6e724a1baa63:emersion_go_bcrypt/vendor/github.com/emersion/go-bcrypt \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-mbox:v1.0.3:emersion_go_mbox/vendor/github.com/emersion/go-mbox \
		emersion:go-message:v0.16.0:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:0145f2c60ead:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.18.0:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-textwrapper:65d896831594:emersion_go_textwrapper/vendor/github.com/emersion/go-textwrapper \
		emersion:go-vcard:8fda7d206ec9:emersion_go_vcard/vendor/github.com/emersion/go-vcard \
		emersion:go-webdav:5d845721d8f7:emersion_go_webdav/vendor/github.com/emersion/go-webdav \
		golang:crypto:v0.12.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.11.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.11.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.12.0:golang_text/vendor/golang.org/x/text

PLIST_FILES=	bin/hydroxide

.include <bsd.port.mk>
