PORTNAME=	apt-mirror
DISTVERSION=	0.5.4-35
DISTVERSIONSUFFIX=	-g088fa51
PORTREVISION=	2
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Debian/Ubuntu apt sources mirroring tool
WWW=		https://apt-mirror.github.io/

LICENSE=	GPL-2.0-only

USES=		perl5 shebangfix
SHEBANG_FILES=	apt-mirror

USE_GITHUB=	yes

RUN_DEPENDS=	wget:ftp/wget

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
