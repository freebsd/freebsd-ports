PORTNAME=	xprobe2
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/xprobe/xprobe2/Xprobe2%20${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ICMP active OS fingerprint scanner
WWW=		http://xprobe.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFIGURE_ENV=	INSTALL=${INSTALL}
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
CC=	clang${LLVM_VERSION}
CPP=	clang-cpp${LLVM_VERSION}
CXX=	clang++${LLVM_VERSION}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DBROKEN_BSD||' ${WRKSRC}/libs-external/USI++/src/configure

.include <bsd.port.mk>
