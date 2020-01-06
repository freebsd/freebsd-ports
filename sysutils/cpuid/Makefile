# Created by: uffe@uffe.org
# $FreeBSD$

PORTNAME=	cpuid
DISTVERSION=	20180519
DISTVERSIONSUFFIX=	.src
CATEGORIES=	sysutils
MASTER_SITES=	http://www.etallen.com/cpuid/
PKGNAMESUFFIX=	${CPUID_SUFFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Tool to dump x86 CPUID information about the CPU(s)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only works with x86 CPUs

USES=		gmake perl5
USE_PERL5=	build
ALL_TARGET=	default
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

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
