PORTNAME=	apt-mirror
DISTVERSION=	0.5.4-29
DISTVERSIONSUFFIX=	-gd1a0a7b
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Debian/Ubuntu apt sources mirroring tool
WWW=		https://apt-mirror.github.io/

LICENSE=	GPLv2

USES=		perl5 shebangfix
SHEBANG_FILES=	apt-mirror

USE_GITHUB=	yes

RUN_DEPENDS=	wget:ftp/wget

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
