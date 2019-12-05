# $FreeBSD$

PORTNAME=	teyjus
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-7
DISTVERSIONSUFFIX=	-ge63f40a
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Higher-order logic programming language Lambda Prolog

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ocamlopt:lang/ocaml \
		omake:devel/omake \
		bash:shells/bash

USES=		dos2unix shebangfix
DOS2UNIX_FILES=	source/OMakefile
SHEBANG_GLOB=	run_test
USE_GITHUB=	yes

EXES=		tjcc tjdepend tjdis tjlink tjsim
PLIST_FILES=	${EXES:S/^/bin\//}

do-build:
	@cd ${WRKSRC} && omake

do-install:
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/source/${e}.opt ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
