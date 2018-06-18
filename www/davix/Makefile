# $FreeBSD$

PORTNAME=	davix
DISTVERSION=	0.6.7
CATEGORIES=	www
MASTER_SITES=	http://grid-deployment.web.cern.ch/grid-deployment/dms/lcgutil/tar/davix/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Make the task of managing files over HTTP-based protocols simple

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limit:^.*\.[0-9]+$$

USES=		cmake localbase ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
