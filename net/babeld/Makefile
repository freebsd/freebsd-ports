PORTNAME=	babeld
PORTVERSION=	1.10
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	gaod@hychen.org
COMMENT=	Distance-vector routing protocol
WWW=		https://www.irif.fr/~jch/software/babel/

LICENSE=	MIT

MAKE_ARGS=	CDEBUGFLAGS="-O2 -g -Wall"

PLIST_FILES=	bin/babeld \
		share/man/man8/babeld.8.gz \
		"@sample etc/babeld.conf.sample"

USE_GITHUB=	yes
GH_ACCOUNT=	jech
USE_RC_SUBR=	babeld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/babeld ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/babeld.man ${STAGEDIR}${PREFIX}/share/man/man8/babeld.8
	${INSTALL_DATA} ${FILESDIR}/babeld.conf ${STAGEDIR}${PREFIX}/etc/babeld.conf.sample

.include <bsd.port.mk>
