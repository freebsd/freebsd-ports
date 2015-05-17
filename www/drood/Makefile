# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	drood
PORTVERSION=	4.3
CATEGORIES=	www
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Lightweight kqueue-based http/1.1 server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_SQLITE=	3
USE_OPENSSL=	yes

PLIST_FILES=	bin/drood \
		man/man8/drood.8.gz \
		etc/rc.d/drood \
		etc/drood/types.tab \
		etc/drood/types.tab.dist

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
BUILD_DEPENDS+=	${LOCALBASE}/lib/libssl.so:${PORTSDIR}/security/openssl
RUN_DEPENDS+=	${LOCALBASE}/lib/libssl.so:${PORTSDIR}/security/openssl
.endif

.include <bsd.port.post.mk>
