PORTNAME=	doinkd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.02
CATEGORIES=	sysutils

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Daemon that logs out idle users and those users hogging resources

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber

LICENSE=	GPLv2

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	STAGEDIR=${STAGEDIR}

post-extract:
	(cd ${WRKSRC}; make clean)

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/doinkd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/doinkd

.include <bsd.port.mk>
