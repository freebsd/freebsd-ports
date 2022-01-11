# Created by: Hung-Yi Chen <gaod@hychen.org>

PORTNAME=	babeld
PORTVERSION=	1.10
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	gaod@hychen.org
COMMENT=	Distance-vector routing protocol

LICENSE=	MIT

MAKE_ARGS=	CDEBUGFLAGS="-O2 -g -Wall"

PLIST_FILES=	bin/babeld \
		man/man8/babeld.8.gz \
		"@sample etc/babeld.conf.sample"

USE_GITHUB=	yes
GH_ACCOUNT=	jech
USE_RC_SUBR=	babeld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/babeld ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/babeld.man ${STAGEDIR}${PREFIX}/man/man8/babeld.8
	${INSTALL_DATA} ${FILESDIR}/babeld.conf ${STAGEDIR}${PREFIX}/etc/babeld.conf.sample

.include <bsd.port.mk>
