# Created by: uffe@uffe.org
# $FreeBSD$

PORTNAME=	cpuid
PORTVERSION=	20140123
CATEGORIES=	sysutils
MASTER_SITES=	http://www.etallen.com/cpuid/
PKGNAMESUFFIX=	${CPUID_SUFFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	uffe@uffe.org
COMMENT=	Tool to dump x86 CPUID information about the CPU(s)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	only works with x86 CPUs

USES=		gmake
ALL_TARGET=	default
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Renamed to avoid conflict with misc/cpuid
CPUID_SUFFIX=	-etallen

PLIST_FILES=	bin/cpuid${CPUID_SUFFIX} \
		man/man1/cpuid${CPUID_SUFFIX}.1.gz

post-patch:
	${REINPLACE_CMD} 's,CFL=.*,& -pthread,' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${STAGEDIR}${PREFIX}/bin/cpuid${CPUID_SUFFIX}
	${INSTALL_MAN} ${WRKSRC}/cpuid.man.gz ${STAGEDIR}${PREFIX}/man/man1/cpuid${CPUID_SUFFIX}.1.gz

.include <bsd.port.mk>
