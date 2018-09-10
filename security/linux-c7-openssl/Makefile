# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.2k
CATEGORIES=	security linux
PKGNAMESUFFIX=	-libs
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL libraries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/usr/share/licenses/${LINUXNAME}-${PORTVERSION}/LICENSE

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
RPMVERSION=	8.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
