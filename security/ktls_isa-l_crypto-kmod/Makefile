# Created by: Michal Bielicki <m.bielicki@llizardfs.com>
# $FreeBSD$

PORTNAME=	isa-l_crypto
PORTVERSION=	2.21.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security
PKGNAMEPREFIX=	ktls_
PKGNAMESUFFIX=	-kmod

MAINTAINER=	gallatin@FreeBSD.org
COMMENT=	KTLS module using Intel(R) ISA-L crypto

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	yasm:devel/yasm

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	01org

MAKE_ENV+=	ISASRC=${WRKSRC}

PLIST_FILES=	${KMODDIR}/ktls_intel-isa-l.ko

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/sys/ktls.h)
IGNORE=		requires KTLS support
.endif

post-extract:
	${CP} ${FILESDIR}/* ${WRKSRC}/
	${ECHO} "#include <sys/stdint.h>" > ${WRKSRC}/include/stdint.h

.include <bsd.port.post.mk>
