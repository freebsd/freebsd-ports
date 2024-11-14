PORTNAME=	trousers
PORTVERSION=	0.3.15
DISTVERSIONSUFFIX=	-5.el9
MASTER_SITES=	EPEL9
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Open-source TCG Software Stack (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://sourceforge.net/projects/trousers/

USES=		cpe linux:rl9
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-lib-${PORTVERSION}${DISTVERSIONSUFFIX}

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
