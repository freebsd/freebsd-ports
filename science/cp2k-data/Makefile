PORTNAME=	cp2k-data
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data for cp2k quantum chemistry package
WWW=		https://www.cp2k.org/

LICENSE=	GPLv2+

USE_GITHUB=	yes
GH_ACCOUNT=	cp2k
GH_PROJECT=	cp2k

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/cp2k

do-install:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
