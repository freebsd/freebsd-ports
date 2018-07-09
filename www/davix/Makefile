# $FreeBSD$

PORTNAME=	davix
DISTVERSIONPREFIX=	R_
DISTVERSION=	0_6_8
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Make the task of managing files over HTTP-based protocols simple

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limit:^.*\.[0-9]+$$

USES=		cmake localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	cern-it-sdc-id
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
