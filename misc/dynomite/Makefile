# $FreeBSD$

PORTNAME=	dynomite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.21-rc2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic dynamo implementation for different k-v storage engines

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool ssl
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Netflix

LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/dynomite-hash-tool \
		man/man8/dynomite.8.gz \
		sbin/dynomite \
		sbin/dynomite-test

.include <bsd.port.mk>
