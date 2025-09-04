PORTNAME=	hydroxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.30
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Free ProtonMail bridge for using with any email client you prefer
WWW=		https://github.com/emersion/hydroxide

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
GH_TUPLE=	ProtonMail:go-crypto:v1.3.0:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		cloudflare:circl:v1.6.1:cloudflare_circl/vendor/github.com/cloudflare/circl \
		emersion:go-bcrypt:6e724a1baa63:emersion_go_bcrypt/vendor/github.com/emersion/go-bcrypt \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-mbox:v1.0.4:emersion_go_mbox/vendor/github.com/emersion/go-mbox \
		emersion:go-message:v0.18.2:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:b788ff22d5a6:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.23.0:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-vcard:c9703dde27ff:emersion_go_vcard/vendor/github.com/emersion/go-vcard \
		emersion:go-webdav:v0.6.0:emersion_go_webdav/vendor/github.com/emersion/go-webdav \
		etcd-io:bbolt:v1.4.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:crypto:v0.40.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.34.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.33.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.27.0:golang_text/vendor/golang.org/x/text

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w"
SUB_LIST=	USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include <bsd.port.mk>
