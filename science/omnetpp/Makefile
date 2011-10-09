# New ports collection makefile for:	omnetpp
# Date created:				29 October 2004
# Whom:					bkoenig
#
# $FreeBSD$
#

PORTNAME=	omnetpp
PORTVERSION=	3.3
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://www.omnetpp.org/download/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	A discrete event simulation environment

LIB_DEPENDS=	BLT24:${PORTSDIR}/x11-toolkits/blt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml libxslt pkgconfig
USE_PERL5=	yes
USE_TCL=	yes
USE_TK=		84+

USE_LDCONFIG=	yes

TCL_VER_NODOT=	${TCL_VER:S/.//}
TK_VER_NODOT=	${TK_VER:S/.//}

LIB_FILES=	cmdenv envir nedxml sim_std tkenv

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGUREUSER=	${WRKSRC}/configure.user
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
PLIST=		${WRKDIR}/pkg-plist

INCLDIR=	${PREFIX}/include/${PORTNAME}
INCLDIR_REL=	${INCLDIR:S,^${PREFIX}/,,}

OPTIONS=	MAGICK "Install ImageMagick for EPS-JPG conversion" ON \
		GRAPHVIZ "Install Graphviz for generating diagrams" ON \
		DOXYGEN "Install Doxygen to create the API reference" ON

.include <bsd.port.pre.mk>

.if defined(WITH_MAGICK)
depend+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_GRAPHVIZ)
depend+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if defined(WITH_DOXYGEN)
depend+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

BUILD_DEPENDS+=	${depend}
RUN_DEPENDS+=	${depend}

pre-configure:
	@${REINPLACE_CMD} \
		-e 's,-O2 -DNDEBUG=1,${CFLAGS} -fPIC,' \
		-e 's,^#MSGC,MSGC,' \
		${WRKSRC}/configure.user
	@${ECHO} "CC=${CC}" >> ${CONFIGUREUSER}
	@${ECHO} "CXX=${CXX}" >> ${CONFIGUREUSER}

	@${ECHO} "OMNETPP_BITMAP_PATH=${DATADIR}/bitmaps" >> ${CONFIGUREUSER}
	@${ECHO} "TK_CFLAGS=\"-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl${TCL_VER} -I${LOCALBASE}/include/tk${TK_VER}\"" >> ${CONFIGUREUSER}
	@${ECHO} "TK_LIBS=\"-L${LOCALBASE}/lib -L${LOCALBASE}/lib -lX11 -ltcl${TCL_VER_NODOT} -ltk${TK_VER_NODOT}\"" >> ${CONFIGUREUSER}
	@${ECHO} "LIBXML_CFLAGS=\"`${PKG_CONFIG} --cflags libxml-2.0`\"" >> ${CONFIGUREUSER}
	@${ECHO} "LIBXML_LIBS=\"`${PKG_CONFIG} --libs libxml-2.0`\"" >> ${CONFIGUREUSER}
	@${ECHO} "WISH=wish${TK_VER}" >> ${CONFIGUREUSER}

pre-install:
	@${CP} pkg-plist ${PLIST}
	@(cd ${WRKSRC}; \
		${FIND} -s include -type f | ${SED} "s,^include,${INCLDIR_REL}," >> ${PLIST}; \
		${FIND} -s -d include -type d | ${SED} "s,^include,@dirrm ${INCLDIR_REL}," >> ${PLIST}; \
	)
	@(cd ${WRKSRC}; \
		${FIND} -s bitmaps -type f | ${SED} "s,^,%%DATADIR%%/," >> ${PLIST}; \
		${FIND} -s -d bitmaps -type d | ${SED} "s,^,@dirrm %%DATADIR%%/," >> ${PLIST} \
	)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; \
		${FIND} -s doc/ -type f | ${SED} "s,^doc/,%%DOCSDIR%%/," >> ${PLIST}; \
		${FIND} -s -d doc/ -type d | ${SED} "s,^doc/,@dirrm %%DOCSDIR%%/," >> ${PLIST} \
	)
.endif
	@${ECHO} "%%DATADIR%%/neddoc.xsl" >> ${PLIST}
	@${ECHO} "%%DATADIR%%/neddocproc.pl" >> ${PLIST}
	@${ECHO} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gned ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/nedtool ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/plove ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/seedtool ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/scalars ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/opp_* ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/splitvec ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/bin/neddoc.xsl ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/neddocproc.pl ${DATADIR}
	@${REINPLACE_CMD} -i '' \
		-e 's,${WRKSRC}/bin,${PREFIX}/bin,' \
		-e 's,${WRKSRC}/include,${INCLDIR},' \
		-e 's,${WRKSRC}/lib,${PREFIX}/lib,' \
		${PREFIX}/bin/opp_makemake
	@${REINPLACE_CMD} -i '' \
		-e 's,^\(.NEDDOC.* = "\).*/\(.*";\),\1${DATADIR}/\2,' \
		${PREFIX}/bin/opp_neddoc
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/*.${PORTVERSION} ${PREFIX}/lib
	@${LN} -s lib${file}.so.${PORTVERSION} ${PREFIX}/lib/lib${file}.so
.endfor
	@(cd ${WRKSRC}/include;\
	${FIND} . -type d -exec ${MKDIR} ${INCLDIR}/{} \; ;\
	${FIND} . -type f | ${XARGS} -I% ${INSTALL_DATA} % ${INCLDIR}/% \
	)
	@(cd ${WRKSRC}/bitmaps;\
	${FIND} . -type d -exec ${MKDIR} ${DATADIR}/bitmaps/{} \; ;\
	${FIND} . -type f | ${XARGS} -I% ${INSTALL_DATA} % ${DATADIR}/bitmaps/% \
	)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc;\
	${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; ;\
	${FIND} . -type f | ${XARGS} -I% ${INSTALL_DATA} % ${DOCSDIR}/% \
	)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
