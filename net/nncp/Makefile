# $FreeBSD$

PORTNAME=	nncp
DISTVERSION=	3.0
CATEGORIES=	net
MASTER_SITES=	http://www.nncpgo.org/download/

MAINTAINER=	stargrave@stargrave.org
COMMENT=	Utilities for secure store-and-forward files, mail, command exchanging

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go:lang/go

USES=		tar:xz
MAKEFILE=	BSDmakefile
USE_RC_SUBR=	nncp-caller nncp-daemon nncp-toss
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message pkg-install pkg-deinstall

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS NEWS NEWS.RU README README.RU THANKS
INFO=		nncp

post-install:
	${INSTALL_DATA} ${FILESDIR}/nncp.newsyslog.conf.sample ${STAGEDIR}${PREFIX}/etc/nncp.conf.sample

.include <bsd.port.mk>
