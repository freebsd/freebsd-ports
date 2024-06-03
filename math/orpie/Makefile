PORTNAME=	orpie
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=	release-
CATEGORIES+=	math

MAINTAINER=	mt-bugs@markoturk.info
COMMENT=	Fullscreen RPN calculator for the console
WWW=		https://pessimization.com/software/orpie/

LICENSE=	GPLv2

NOT_FOR_ARCHS=		armv6 armv7
NOT_FOR_ARCHS_REASON=	architectures with double-word alignment for doubles are not supported

BUILD_DEPENDS=	ocaml-camlp5>=0:devel/ocaml-camlp5 \
		${LOCALBASE}/${OCAML_SITELIBDIR}/camlp-streams/META:devel/ocaml-camlp-streams \
		${LOCALBASE}/${OCAML_SITELIBDIR}/curses/META:devel/ocaml-curses \
		${LOCALBASE}/${OCAML_SITELIBDIR}/gsl/META:math/ocamlgsl \
		${LOCALBASE}/${OCAML_SITELIBDIR}/num/META:math/ocaml-num
LIB_DEPENDS=	libgsl.so:math/gsl

USES=		ncurses ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	pelzlpj
USE_OCAML=	yes
#XXX DUNE_DOCSDIR=	${DOCSDIR}

PORTDOCS=	LICENSE.md README.adoc manual.html manual.pdf
PLIST_FILES=	bin/orpie bin/orpie-curses-keys  \
		share/man/man1/orpie.1.gz share/man/man1/orpie-curses-keys.1.gz \
		share/man/man5/orpierc.5.gz
# upstream changed to etc/orpie/orpierc, we stick to the old name (POLA)
PLIST_FILES+=	"@sample etc/orpierc.sample"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's,#use "topfind",#directory "+unix",' \
		-e 's,#require "unix",#load "unix.cma",' \
		${WRKSRC}/scripts/compute_prefix
	@${REINPLACE_CMD} \
		-e 's,(libraries,& camlp-streams,' \
		${WRKSRC}/src/orpie/dune
	@${REINPLACE_CMD} \
		-e '/^let sysconfdir =/s,"etc/orpie","etc",' \
		${WRKSRC}/src/orpie/install.ml.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:@f@${STAGEDIR}${OCAML_DOCSDIR}/${PORTNAME}/$f@} \
		${STAGEDIR}${DOCSDIR}
	@${RM} ${PORTDOCS:@f@${STAGEDIR}${OCAML_DOCSDIR}/${PORTNAME}/$f@}
	@${RMDIR} ${STAGEDIR}${OCAML_DOCSDIR}/${PORTNAME} ${STAGEDIR}${OCAML_DOCSDIR}
	@${RM} -r ${STAGEDIR}${PREFIX}/${OCAML_LIBDIR}
	@${MV} ${STAGEDIR}${ETCDIR}/orpierc ${STAGEDIR}${PREFIX}/etc/orpierc.sample
	@${RMDIR} ${STAGEDIR}${ETCDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
