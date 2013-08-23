# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	chucky
PORTVERSION=	1.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	waitman@waitman.net
COMMENT=	Port installed version check/report with shar archival

LICENSE=	CHUCKY
LICENSE_NAME=	CHUCKY BSD LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

LIB_DEPENDS=	pkg:${PORTSDIR}/ports-mgmt/pkg \
		sqlite3:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_PROJECT=	chucky
GH_TAGNAME=	075defe
GH_COMMIT=	${GH_TAGNAME}

WRKSRC=		${WRKDIR}/waitman-chucky-075defe

MAN7=		chucky.7

SUB_FILES=	pkg-message
SUB_LIST=	MAN7PREFIX="${MAN7PREFIX}"
PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
