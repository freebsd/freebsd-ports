# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	userfw
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net kld
MASTER_SITES=	http://userfw.net/files/release/ \
		http://imax.in.ua/files/ \
		http://projects.ukrweb.net/files/

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Modular packet filter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

SSP_UNSAFE=	kernel module does not support ssp
USES=		cmake:outsource kmod tar:xz uidfix
USE_LDCONFIG=	yes

BROKEN_powerpc=	does not compile

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/sys/module.h)
IGNORE=		requires kernel source files
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1100000
BROKEN=		does not build on FreeBSD 11+
.endif

CMAKE_ARGS+=	-DDOMAIN_STUB:BOOL=OFF
CMAKE_ARGS+=	-DOPCODE_VERIFICATION:BOOL=OFF
CMAKE_ARGS+=	-DKMODDIR="${KMODDIR}"

.include <bsd.port.post.mk>
