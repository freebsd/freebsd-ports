PORTNAME=	babeld
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.13.1
CATEGORIES=	net

MAINTAINER=	gaod@hychen.org
COMMENT=	Distance-vector routing protocol
WWW=		https://www.irif.fr/~jch/software/babel/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USE_GITHUB=	yes
GH_ACCOUNT=	jech
GH_TUPLE=	BLAKE2:BLAKE2:320c325:BLAKE2/BLAKE2 \
		massar:rfc6234:285c8b8:rfc6234/rfc6234
USE_RC_SUBR=	babeld

MAKE_ARGS=	CFLAGS+="${CFLAGS}"

PLIST_FILES=	bin/babeld \
		share/man/man8/babeld.8.gz \
		"@sample etc/babeld.conf.sample"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/babeld ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/babeld.man ${STAGEDIR}${PREFIX}/share/man/man8/babeld.8
	${INSTALL_DATA} ${FILESDIR}/babeld.conf ${STAGEDIR}${PREFIX}/etc/babeld.conf.sample

.include <bsd.port.mk>
