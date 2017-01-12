# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	openssl-compat
PORTVERSION=	0.9.8e
PORTREVISION=	5
CATEGORIES=	security linux
DISTNAME=	openssl098e-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/usr/share/doc/openssl098e-${PORTVERSION}/LICENSE

CONFLICTS=	linux-f10-openssl-[0-9]*

USES=		linux:c6
USE_LINUX_RPM=	yes
RPMVERSION=	20.el6.centos.1
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../openssl/pkg-descr

post-install:
# For libflashsupport.so in www/linux-c6-flashplugin11.
	${LN} -sf libssl.so.6 ${STAGEDIR}${PREFIX}/usr/lib/libssl.so.7

.include <bsd.port.mk>
