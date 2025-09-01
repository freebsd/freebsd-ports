PORTNAME=	httm
DISTVERSION=	0.48.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Dream of a CLI Time Machine
WWW=		https://github.com/kimono-koans/httm

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Fails to build: non-binding let on a synchronization lock

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kimono-koans

PLIST_FILES=	bin/httm

.include <bsd.port.mk>
