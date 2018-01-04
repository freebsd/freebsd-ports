# $FreeBSD$

PORTNAME=		fastd
PORTVERSION=		18.a.20151111
PORTREVISION=		5
CATEGORIES=		security net
MASTER_SITES=		https://git.universe-factory.net/fastd/snapshot/
PKGNAMESUFFIX=		-devel
DISTNAME=		999b87b80302dbc14e23ef3dff187b91dae7fab5

MAINTAINER=		crest_maintainer@rlwinm.de
COMMENT=		Fast and Secure Tunnelling Daemon

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/COPYRIGHT

BROKEN=			fails to build

LIB_DEPENDS=		libjson-c.so:devel/json-c       \
			libsodium.so:security/libsodium \
			libuecc.so:security/libuecc

USES=			bison cmake:outsource pkgconfig tar

USE_RC_SUBR=		fastd_devel

PLIST_FILES=		bin/fastd-devel           \
			man/man1/fastd-devel.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fastd.1 ${STAGEDIR}${PREFIX}/man/man1/fastd-devel.1

.include <bsd.port.mk>
