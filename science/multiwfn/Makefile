# $FreeBSD$

PORTNAME=	multiwfn
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1-0-14
PORTREVISION=	1
DISTVERSIONSUFFIX=	-ge873677
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multifunctional wavefunction analysis for quantum chemistry

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake fortran shebangfix
SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	init/Multiwfn.01
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	stecue
GH_PROJECT=	gMultiwfn

PLIST_FILES=	bin/Multiwfn \
		lib/gMultiwfn/Multiwfn

.include <bsd.port.mk>
