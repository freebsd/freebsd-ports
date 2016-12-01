# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	yorick
DISTVERSIONPREFIX=	y_
DISTVERSION=	2_2_04
PORTREVISION=	1
CATEGORIES=	lang math

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Interpreted language for scientific simulations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		makeinfo
USE_XORG=	x11
MAKE_ARGS=	Y_HOME=relocatable Y_DOCDIR=/dev/null

USE_GITHUB=	yes
GH_ACCOUNT=	dhmunro

INFO=		yorick
PORTDOCS=	FILE_FORMATS README drat.doc graph.doc hex.doc \
		library.doc math.doc refs.pdf refs.tex std.doc \
		yorick.pdf yorick.tex

OPTIONS_DEFINE=	DOCS

# Change "cd foo; $(MAKE)" into "$(MAKE) -C foo" to unbreak parallel builds
post-patch:
	@${REINPLACE_CMD} -e 's|libyor\.a$$|libyor|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|' \
		${WRKSRC}/gist/Makefile ${WRKSRC}/play/Makefile \
		${WRKSRC}/yorick/Makefile ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/-ldl[[:>:]]//' ${WRKSRC}/play/unix/config.sh

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ysite config

post-build:
	${MAKE} -C ${WRKSRC}/doc yorick.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/emacs/yorick.el ${WRKSRC}/relocatable
	@${RM} -r ${WRKSRC}/relocatable/doc ${PREFIX}/lib/${PORTNAME}
	@${MV} ${WRKSRC}/relocatable ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.for f in gist yorick
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/bin/${f}
	${LN} -sf ../lib/${PORTNAME}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/lib/codger
	${INSTALL_DATA} ${WRKSRC}/doc/yorick.info* \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	${LN} -sf ../../${DOCSDIR_REL} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/doc

.include <bsd.port.mk>
