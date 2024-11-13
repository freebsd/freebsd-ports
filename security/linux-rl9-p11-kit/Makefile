PORTNAME=	p11-kit
PORTVERSION=	0.25.3
DISTVERSIONSUFFIX=	-2.el9
PORTREVISION=	1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://p11-glue.freedesktop.org/p11-kit.html

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libtasn1
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${DISTNAME} \
		p11-kit-trust-${DISTVERSION}${DISTVERSIONSUFFIX}

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/usr/lib64/pkcs11/p11-kit-trust.so ${STAGEDIR}${PREFIX}/usr/lib64/libnssckbi.so
.if ${ARCH} == amd64
	${RLN} ${STAGEDIR}${PREFIX}/usr/lib/pkcs11/p11-kit-trust.so ${STAGEDIR}${PREFIX}/usr/lib/libnssckbi.so
.endif

.include <bsd.port.mk>
