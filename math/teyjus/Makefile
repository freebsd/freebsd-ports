PORTNAME=	teyjus
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-7
DISTVERSIONSUFFIX=	-ge63f40a
PORTREVISION=	1
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Higher-order logic programming language Lambda Prolog
WWW=		http://teyjus.cs.umn.edu/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	omake:devel/omake \
		bash:shells/bash

USES=		dos2unix shebangfix
DOS2UNIX_FILES=	source/OMakefile
SHEBANG_GLOB=	run_test
USE_OCAML=	yes
USE_GITHUB=	yes

CFLAGS+=	-Wno-error=comment
EXES=		tjcc tjdepend tjdis tjlink tjsim
PLIST_FILES=	${EXES:S/^/bin\//}

# replacing bundled and outdated OCaml headers with a symlink to
# the current headers
post-patch:
	${RM} -r ${WRKSRC}/source/front/caml
	${LN} -s ${LOCALBASE}/${OCAML_LIBDIR}/caml ${WRKSRC}/source/front/caml

do-build:
	@(cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} omake)

do-install:
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/source/${e}.opt ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
