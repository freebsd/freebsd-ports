# $FreeBSD$

PORTNAME=		fastd
PORTVERSION=		18
PORTREVISION=		3
CATEGORIES=		security net
MASTER_SITES=		https://git.universe-factory.net/fastd/snapshot/

MAINTAINER=		crest_maintainer@rlwinm.de
COMMENT=		Fast and Secure Tunnelling Daemon

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/COPYRIGHT

BROKEN=			fails to build

LIB_DEPENDS=		libjson-c.so:devel/json-c       \
			libsodium.so:security/libsodium \
			libuecc.so:security/libuecc

USES=			bison cmake:outsource pkgconfig tar

USE_RC_SUBR=		fastd

PLIST_FILES=		bin/fastd           \
			man/man1/fastd.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fastd.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
