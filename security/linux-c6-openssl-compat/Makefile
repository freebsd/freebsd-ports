# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	openssl-compat
PORTVERSION=	0.9.8e
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux CentOS ${LINUX_DIST_VER})
DISTNAME=	openssl098e-${PORTVERSION}-${RPMVERSION}

CONFLICTS=	linux-openssl-[0-9]* linux-f8-openssl-[0-9]* linux-f10-openssl-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_RPM=	yes
RPMVERSION=	17.el6.centos.2
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../openssl/pkg-descr

post-install:
	@cd ${STAGEDIR}${PREFIX}/usr/lib && ${LN} -sf libssl.so.6 libssl.so.7

.include <bsd.port.mk>
