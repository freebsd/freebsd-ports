PORTNAME=	hydroxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.33
CATEGORIES=	mail

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Free ProtonMail bridge for using with any email client you prefer
WWW=		https://codeberg.org/emersion/hydroxide

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_FORGEJO=	yes
FJ_ACCOUNT=	emersion
USE_GITHUB=	nodefault
GH_TUPLE=	ProtonMail:go-crypto:v1.5.2:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		cloudflare:circl:v1.6.5:cloudflare_circl/vendor/github.com/cloudflare/circl \
		emersion:go-bcrypt:6e724a1baa63:emersion_go_bcrypt/vendor/github.com/emersion/go-bcrypt \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-mbox:v1.0.4:emersion_go_mbox/vendor/github.com/emersion/go-mbox \
		emersion:go-message:v0.18.2:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:b788ff22d5a6:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.25.0:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-vcard:v0.1.0:emersion_go_vcard/vendor/github.com/emersion/go-vcard \
		emersion:go-webdav:v0.7.0:emersion_go_webdav/vendor/github.com/emersion/go-webdav \
		etcd-io:bbolt:v1.5.0:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:crypto:v0.58.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.49.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.47.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.43.0:golang_text/vendor/golang.org/x/text

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w"
SUB_LIST=	USER=${USERS}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^0\.2\.

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}/* ${WRKSRC}
	${RM} -r ${WRKDIR}/${PORTNAME}

post-patch:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include <bsd.port.mk>
