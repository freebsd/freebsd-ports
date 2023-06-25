PORTNAME=	cyrus-sasl
PORTVERSION=	2.1.27
DISTVERSIONSUFFIX=	-21.el9
CATEGORIES=	security linux
PKGNAMESUFFIX=	-lib

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer) (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.cyrusimap.org/sasl/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
