PORTNAME=	p11-kit
PORTVERSION=	0.25.3
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://p11-glue.freedesktop.org/p11-kit.html

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libtasn1
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		p11-kit-trust-${DISTVERSION}${DISTVERSIONSUFFIX}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/usr/lib64/pkcs11/p11-kit-trust.so ${STAGEDIR}${PREFIX}/usr/lib64/libnssckbi.so

.include <bsd.port.mk>
