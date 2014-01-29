# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	htmlc
PORTVERSION=	2.21.0
CATEGORIES=	textproc
MASTER_SITES=	http://htmlc.inria.fr/ \
		http://caml.inria.fr/distrib/bazar-ocaml/htmlc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	A text file generator

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

USES=	gmake

PLIST_FILES=	bin/htmlc bin/htmlc.byt share/htmlc/env
PLIST_DIRS=	share/htmlc
PORTDOCS=	LICENSE INSTALL README JoeCaml.gif rocq.gif copyright-eng.htm \
		copyright-fra.htm eng.htm fra.htm index.htm

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${LOCALBASE}

.include <bsd.port.pre.mk>

post-patch:
	${RM} -f ${WRKSRC}/doc/Makefile
	${TOUCH} ${WRKSRC}/doc/Makefile
	${ECHO} "all:" > ${WRKSRC}/doc/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compiler/htmlc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/compiler/htmlc.byt ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config/env ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/JoeCaml.gif ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rocq.gif ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/copyright-eng.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/copyright-fra.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/eng.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fra.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
