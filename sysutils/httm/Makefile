PORTNAME=	httm
DISTVERSION=	0.37.9
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Dream of a CLI Time Machine
WWW=		https://github.com/kimono-koans/httm

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kimono-koans

.include "${.CURDIR}/Makefile.cargo"

PLIST_FILES=	bin/httm

.include <bsd.port.mk>
