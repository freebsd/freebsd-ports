# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	openssl-compat
PORTVERSION=	0.9.8e
PORTREVISION=	3
CATEGORIES=	security linux
DISTNAME=	openssl098e-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenSSL toolkit (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-openssl-[0-9]* linux-f10-openssl-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	20.el6.centos.1
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../openssl/pkg-descr

post-install:
.	if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == "c6_64"
	@cd ${STAGEDIR}${PREFIX}/usr/lib64 && ${LN} -sf libssl.so.6 libssl.so.7
.	else
	@cd ${STAGEDIR}${PREFIX}/usr/lib && ${LN} -sf libssl.so.6 libssl.so.7
.	endif

.include <bsd.port.mk>
