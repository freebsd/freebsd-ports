# New ports collection makefile for:	omnetpp
# Date created:				29 October 2004
# Whom:					bkoenig
#
# $FreeBSD$
#

PORTNAME=	omnetpp
PORTVERSION=	2.3p1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.omnest.biz/download/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	bkoenig@cs.tu-berlin.de
COMMENT=	A discrete event simulation environment

USE_BISON=	yes

TCL_VERSION?=	tcl8.4
TK_VERSION?=	tk8.4

TCL_NODOT=	${TCL_VERSION:S/.//}
TK_NODOT=	${TK_VERSION:S/.//}

LIB_DEPENDS=	${TCL_NODOT}:${PORTSDIR}/lang/${TCL_NODOT} \
		${TK_NODOT}:${PORTSDIR}/x11-toolkits/${TK_NODOT} \
		expat:${PORTSDIR}/textproc/expat2

.include <bsd.port.pre.mk>

COMPONENTS=	libs progs

INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes

LIB_FILES=	cmdenv envir nedxml sim_std tkenv

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGUREUSER=	${WRKSRC}/configure.user

post-extract:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/gned/ebnf.tab.cc ${WRKSRC}/src/gned/ebnf.y \
		${WRKSRC}/src/nedc/ebnf.tab.c ${WRKSRC}/src/nedc/ebnf.y \
		${WRKSRC}/src/nedxml/ned.tab.c ${WRKSRC}/src/nedxml/ned.y

pre-configure:
.if defined(CFLAGS)
	@${REINPLACE_CMD} -e 's,-O3 -DNDEBUG=1,${CFLAGS},' ${WRKSRC}/configure.user
.endif
	@${ECHO} "OMNETPP_ROOT=${PREFIX}" >> ${CONFIGUREUSER}
	@${ECHO} "OMNETPP_GNED_DIR=${DATADIR}/gned" >> ${CONFIGUREUSER}
	@${ECHO} "OMNETPP_PLOVE_DIR=${DATADIR}/plove" >> ${CONFIGUREUSER}
	@${ECHO} "OMNETPP_TKENV_DIR=${DATADIR}/tkenv" >> ${CONFIGUREUSER}
	@${ECHO} "OMNETPP_BITMAP_PATH=${DATADIR}/bitmaps" >> ${CONFIGUREUSER}
	@${ECHO} "TK_CFLAGS=\"-I${X11BASE}/include -I${LOCALBASE}/include/${TCL_VERSION} -I${LOCALBASE}/include/${TK_VERSION}\"" >> ${CONFIGUREUSER}
	@${ECHO} "TK_LIBS=\"-L${X11BASE}/lib -L${LOCALBASE}/lib -lX11 -l${TCL_NODOT} -l${TK_NODOT}\"" >> ${CONFIGUREUSER}
	@${ECHO} "EXPAT_CFLAGS=\"-I${LOCALBASE}/include\"" >> ${CONFIGUREUSER}
	@${ECHO} "EXPAT_LIBS=\"-L${LOCALBASE}/lib -lexpat\"" >> ${CONFIGUREUSER}
	@${ECHO} "WISH=wish${TK_VERSION}" | ${SED} 's,tk,,' >> ${CONFIGUREUSER}

post-configure:
.if defined(COMPONENTS)
	@${REINPLACE_CMD} -e 's,libs progs samples tutorials,${COMPONENTS},' \
		${WRKSRC}/Makefile
.endif

do-install:
	@${REINPLACE_CMD} -e 's,${WRKSRC}/include,${PREFIX}/include/${PORTNAME},' \
		${WRKSRC}/bin/opp_makemake
	@${REINPLACE_CMD} -e 's,${WRKSRC}/lib,${PREFIX}/lib,' \
		${WRKSRC}/bin/opp_makemake
	@${REINPLACE_CMD} -e 's,${WRKSRC}/doc,${DOCSDIR},' \
		${WRKSRC}/bin/opp_makemake
	@${REINPLACE_CMD} -e 's,${WRKSRC}/src,${DATADIR},' \
		${WRKSRC}/bin/plove
	@${MKDIR} ${PREFIX}/include/${PORTNAME} \
  		${DATADIR}/bitmaps ${DATADIR}/gned ${DATADIR}/plove ${DATADIR}/tkenv
	@${RM} ${WRKSRC}/bin/opp_makemake.bak
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gned ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/nedc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/nedtool ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/seedtool ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/opp_* ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/plove ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/splitvec ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/bin/neddoc.xsl ${PREFIX}/bin
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/*.${PORTVERSION} ${PREFIX}/lib
	@${LS} ${PREFIX}/lib/lib${file}.so.${PORTVERSION} | ${SED} s/.${PORTVERSION}// | ${XARGS} -I% ${LN} -s %.${PORTVERSION} %
.endfor
	@${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${DATADIR}/bitmaps
	@${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/include/doxy.cfg ${PREFIX}/include/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/src/gned/*.tcl ${DATADIR}/gned
	@${INSTALL_DATA} ${WRKSRC}/src/plove/*.tcl ${DATADIR}/plove
	@${INSTALL_DATA} ${WRKSRC}/src/plove/*.sh ${DATADIR}/plove
	@${INSTALL_DATA} ${WRKSRC}/src/plove/demo.vec ${DATADIR}/plove
	@${INSTALL_DATA} ${WRKSRC}/src/tkenv/*.tcl ${DATADIR}/tkenv

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} 444
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
