# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openssl
PKGNAMESUFFIX=	-compat
PORTVERSION=	0.9.8e
CATEGORIES=	security linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}/LICENSE

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}${PKGNAMESUFFIX}-[0-9]*

LINUX_NAME=	openssl098e
RPMVERSION=	29.el7.centos.3
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}

post-install:
# For libflashsupport.so in www/linux-c7-flashplugin11.
	${LN} -sf libssl.so.6 ${STAGEDIR}${PREFIX}/usr/lib/libssl.so.7

.include <bsd.port.mk>
