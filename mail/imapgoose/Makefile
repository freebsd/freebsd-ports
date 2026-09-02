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

USE_GITHUB=	nodefault
GH_TUPLE=	emersion:go-message:v0.18.2:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:b788ff22d5a6:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.13.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.5.0:golang_term/vendor/golang.org/x/term \
		lmittmann:tint:v1.1.2:lmittmann_tint/vendor/github.com/lmittmann/tint \
		mattn:go-sqlite3:v1.14.24:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		whynothugo:go-imap:cfb5560bc8dc:whynothugo_go_imap_v2/vendor/github.com/emersion/go-imap/v2

# Patterned on _SRHT_TUPLE in mail/aerc
_CODEBERG_TUPLE=	emersion:go-scfg:v0.1.0:vendor/codeberg.org/emersion/go-scfg

.for account project tag subdir in ${_CODEBERG_TUPLE:S/:/ /g}
MASTER_SITES+=	https://codeberg.org/${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project:S/-/_/g}
DISTFILES+=	${account}-${project}-${tag}_CODEBERG0${EXTRACT_SUFX}:${account}_${project:S/-/_/g}
.endfor

GO_TARGET=	./cmd/imapgoose

post-extract:
.for account project tag subdir in ${_CODEBERG_TUPLE:S/:/ /g}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${MV} ${WRKDIR}/${project} ${WRKSRC}/${subdir}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/imapgoose.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/imapgoose.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/

.include <bsd.port.mk>
