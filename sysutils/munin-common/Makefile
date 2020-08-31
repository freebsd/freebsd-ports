# Created by: Sean Rees <sean@rees.us>
# $FreeBSD$

PORTNAME=	munin
PORTVERSION=	${MUNIN_VERSION}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MUNIN_SITES}
PKGNAMESUFFIX=	-common

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Common components between a munin node and server

BUILD_DEPENDS=	p5-Module-Build>=0:devel/p5-Module-Build \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay
RUN_DEPENDS=	p5-Net-SSLeay>=0:security/p5-Net-SSLeay

USES=		cpe gmake perl5

.include "${.CURDIR}/../munin-common/munin.mk"

ALL_TARGET=	build-common
INSTALL_TARGET=	install-common
NO_ARCH=	yes

post-install:
	${MKDIR} ${STAGEDIR}${LOGDIR} ${STAGEDIR}${STATEDIR} ${STAGEDIR}${SPOOLDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
