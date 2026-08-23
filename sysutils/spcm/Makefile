PORTNAME=	spcm
DISTVERSION=	0.5.9
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters
WWW=		https://github.com/outpaddling/SPCM

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	auto-admin>=0.8.5:sysutils/auto-admin

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_PROJECT=	SPCM

MAKE_ENV+=	DATADIR=${DATADIR}

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cluster-passwd

.include <bsd.port.mk>
