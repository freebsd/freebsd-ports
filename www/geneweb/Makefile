# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	geneweb
DISTVERSIONPREFIX=	distrib-
DISTVERSION=	6-08
CATEGORIES=	www

MAINTAINER=	alex@stangl.us
COMMENT=	Advanced genealogy software

LICENSE=	GPLv2

BUILD_DEPENDS=	ocamlc:lang/ocaml \
		camlp5:devel/ocaml-camlp5

USE_GITHUB=	yes
GH_ACCOUNT=	geneanet

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
