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

#MAN1=		htmlc.1

PLIST_FILES=	bin/htmlc bin/htmlc.byt share/htmlc/env
PLIST_DIRS=	share/htmlc
PORTDOCS=	LICENSE INSTALL README JoeCaml.gif rocq.gif copyright-eng.htm \
		copyright-fra.htm eng.htm fra.htm index.htm

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${LOCALBASE}
USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	${RM} -f ${WRKSRC}/doc/Makefile
	${TOUCH} ${WRKSRC}/doc/Makefile
	${ECHO} "all:" > ${WRKSRC}/doc/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/compiler/htmlc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/compiler/htmlc.byt ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/config/env ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/LICENSE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/INSTALL ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/JoeCaml.gif ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rocq.gif ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/copyright-eng.htm ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/copyright-fra.htm ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/eng.htm ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/fra.htm ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/index.htm ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
