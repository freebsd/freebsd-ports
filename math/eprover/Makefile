PORTNAME=	eprover
DISTVERSIONPREFIX=	E-
DISTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover for full first-order logic with equality
WWW=		https://www.eprover.org

LICENSE=	LGPL20+ GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		help2man:misc/help2man
RUN_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	etc/bjob_classify \
		development_tools/spec_version.sh \
		PYTHON/bsub_eprover.py

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--bindir=${STAGEDIR}${PREFIX}/bin/ \
		--man-prefix=${STAGEDIR}${PREFIX}/share/man/man1/
MAKE_ARGS=	CC=${CC}

ALL_TARGET=	all man

BINARY_ALIAS=	make=${GMAKE} \
		gcc=${CC}

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*$$ # prevent versions like git-export-2012-06-29

post-install:
	# strip binaries
.for f in checkproof e_axfilter e_deduction_server e_ltb_runner e_stratpar eground \
	  ekb_create ekb_delete ekb_ginsert ekb_insert epclextract eprover
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	# remove the unnecessary 'picosat' executable
	@${RM} ${STAGEDIR}${PREFIX}/bin/picosat

.include <bsd.port.mk>
