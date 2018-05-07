# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	geneweb
DISTVERSIONPREFIX=	distrib-
DISTVERSION=	6-08
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	alex@stangl.us
COMMENT=	Advanced genealogy software

LICENSE=	GPLv2

BUILD_DEPENDS=	ocamlc:lang/ocaml \
		camlp5:devel/ocaml-camlp5 \
		ocamlfind:devel/ocaml-findlib

USE_GITHUB=	yes
GH_ACCOUNT=	geneweb
GH_TAGNAME=	13c850a0cc3973daf7ae3e0772a1621f84052041

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	STAGEDIR=${STAGEDIR}
SUB_FILES+=	pkg-message
USE_RC_SUBR=	gwd

post-install:
	(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} distrib)
	${INSTALL_DATA} ${WRKSRC}/etc/a.gwf ${STAGEDIR}${PREFIX}/share/geneweb
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/geneweb/distribution
	@${CP} -a ${WRKSRC}/distribution ${STAGEDIR}${PREFIX}/share/geneweb/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gwc1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/geneweb/distribution/gw/gwc1
	${INSTALL_SCRIPT} ${FILESDIR}/install.sh ${STAGEDIR}${PREFIX}/share/geneweb

.include <bsd.port.mk>
