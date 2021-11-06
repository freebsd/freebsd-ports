PORTNAME=	spcm
DISTVERSION=	0.5.4-9
DISTVERSIONSUFFIX=	-g64cd7ee
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for building and managing HPC clusters

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	auto-admin>=0.7.6.11:sysutils/auto-admin

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling
GH_PROJECT=	SPCM

MAKE_ENV+=	DATADIR=${DATADIR}

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cluster-passwd

.include <bsd.port.mk>
