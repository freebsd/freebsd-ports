PORTNAME=	geneweb
DISTVERSIONPREFIX=	distrib-
DISTVERSION=	6-08
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced genealogy software
WWW=		https://opensource.geneanet.org/projects/geneweb/

LICENSE=	GPLv2

BUILD_DEPENDS=	ocamlc:lang/ocaml \
		camlp5:devel/ocaml-camlp5 \
		ocamlfind:devel/ocaml-findlib

USE_GITHUB=	yes
GH_ACCOUNT=	geneweb
GH_TAGNAME=	13c850a0cc3973daf7ae3e0772a1621f84052041

CONFLICTS_INSTALL=	coreutils # bin/gwc

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	STAGEDIR=${STAGEDIR}
SUB_FILES+=	pkg-message
USE_RC_SUBR=	gwd

post-patch:
	@${REINPLACE_CMD} \
		-e 's,^OCAMLC=.*,OCAMLC=ocamlfind ocamlc -package camlp5.streams -package camlp5.gramlib -package unix -package str -w -3 -warn-error +a-52 -unsafe-string,' \
		-e 's,^OCAMLOPT=.*,OCAMLOPT=ocamlfind ocamlopt -package camlp5.streams -package camlp5.gramlib -package unix -package str -w -3 -warn-error +a-52 -unsafe-string,' \
		${WRKSRC}/tools/Makefile.inc.unix

post-install:
	(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} distrib)
	${INSTALL_DATA} ${WRKSRC}/etc/a.gwf ${STAGEDIR}${PREFIX}/share/geneweb
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/geneweb/distribution
	@${CP} -a ${WRKSRC}/distribution ${STAGEDIR}${PREFIX}/share/geneweb/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gwc1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/geneweb/distribution/gw/gwc1
	${INSTALL_SCRIPT} ${FILESDIR}/install.sh ${STAGEDIR}${PREFIX}/share/geneweb

.include <bsd.port.mk>
