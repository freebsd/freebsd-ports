# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.1e
PORTREVISION=	3
CATEGORIES=	security linux
MASTER_SITES=	CENTOS_LINUX/centos/7.3.1611/updates/x86_64/Packages/ \
		CENTOS_LINUX/centos/7.3.1611/updates/Source/SPackages/
LIB_DISTFILES=	${PORTNAME}-libs-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/usr/share/doc/${PORTNAME}-libs-${PORTVERSION}/LICENSE

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-libs-${PORTVERSION}
RPMVERSION=	60.el7_3.1
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
