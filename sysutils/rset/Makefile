PORTNAME=	rset
DISTVERSION=	2.1
CATEGORIES=	sysutils
MASTER_SITES=	https://scriptedconfiguration.org/code/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configure systems using using any scripting language

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	YES
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
TEST_TARGET=	TEST

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/rset \
		${STAGEDIR}${PREFIX}/bin/miniquark

.include <bsd.port.mk>
