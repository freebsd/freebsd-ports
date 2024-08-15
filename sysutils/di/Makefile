PORTNAME=	di
DISTVERSION=	4.53
CATEGORIES=	sysutils
MASTER_SITES=	SF/diskinfo-di

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Disk Information Utility
WWW=		https://diskinfo-di.sourceforge.io/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	test

MAKE_ARGS=	-e
MAKE_ENV=	prefix="${PREFIX}"
TEST_TARGET=	test

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_MAKE_ENV_OFF=	DI_NO_NLS=T

pre-install:
	@${STRIP_CMD} ${WRKSRC}/C/di

.include <bsd.port.mk>
