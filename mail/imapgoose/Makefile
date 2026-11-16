PORTNAME=	imapgoose
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES=	mail
MASTER_SITES=	https://git.sr.ht/~whynothugo/ImapGoose/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTNAME=	ImapGoose-${DISTVERSIONFULL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	juhani@krekela.fi
COMMENT=	Keep local Maildir directories synchronised with an IMAP server
WWW=		https://git.sr.ht/~whynothugo/ImapGoose

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules

USE_FORGEJO=	nodefault
FJ_TUPLE=	emersion:go-scfg:v0.1.0:emersion_go_scfg/vendor/codeberg.org/emersion/go-scfg

USE_GITHUB=	nodefault
GH_TUPLE=	emersion:go-message:v0.18.2:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:b788ff22d5a6:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.13.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.5.0:golang_term/vendor/golang.org/x/term \
		lmittmann:tint:v1.1.2:lmittmann_tint/vendor/github.com/lmittmann/tint \
		mattn:go-sqlite3:v1.14.24:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		whynothugo:go-imap:cfb5560bc8dc:whynothugo_go_imap_v2/vendor/github.com/emersion/go-imap/v2

GO_TARGET=	./cmd/imapgoose

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${ARCH} == "i386"
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-i386-internal_watcher_backend__bsd.go
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/imapgoose.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/imapgoose.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/

.include <bsd.port.mk>
