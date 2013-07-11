# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	prhistory
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH

MAINTAINER=	waitman@waitman.net
COMMENT=	PR review for ports

LICENSE=	PRHISTORY
LICENSE_NAME=	PRHISTORY BSD LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		sqlite3:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9113c59

MAN7=	prhistory.7

SUB_FILES=	pkg-message
PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
