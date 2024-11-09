PORTNAME=	imap-tools
DISTVERSION=	1.2.0
CATEGORIES=	mail
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A collection of tools to manipulate IMAP mailboxes
WWW=		https://gitlab.com/mat813/imap-tools

LICENSE=	MIT

USES=		cargo

PLIST_FILES=	bin/imap-tools

# make cargo-crates > Makefile.crates

.include <bsd.port.mk>
