# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	js@jeannot.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	xless:${PORTSDIR}/misc/xless \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83 \
		pvm:${PORTSDIR}/net/pvm

PVM_ROOT=	${PREFIX}/lib/pvm

NO_CDROM=	"Don't sell for profit."

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--without-xless --with-tk \
		--with-tk-library=${PREFIX}/lib --with-tk-include=${PREFIX}/include/tk8.3 \
		--with-tcl-library=${PREFIX}/lib --with-tcl-include=${PREFIX}/include/tcl8.3 \
		--with-xaw3d

CONFIGURE_ENV=	PVM_ROOT=${PVM_ROOT} PVM_LIB=${PREFIX}/lib
MAKE_ENV=	PVM_INCLUDE=${PREFIX}/include

post-extract:
	${RM} ${WRKSRC}/examples/callsci/callsciJava/config/config
	${RM} ${WRKSRC}/examples/callsci/callsciFortran/config/config
	${RM} ${WRKSRC}/examples/callsci/callsciC/config/config
	${RM} ${WRKSRC}/examples/callsci/callsciC++/config/config

pre-patch:
	${TR} -d '\015' < ${WRKSRC}/macros/util/formatman.sci \
		> ${WRKSRC}/macros/util/formatman.sci.new
	${MV} ${WRKSRC}/macros/util/formatman.sci.new \
		${WRKSRC}/macros/util/formatman.sci

post-patch:
	@${REINPLACE_CMD} -e 's,%%PVM_ROOT%%,${PVM_ROOT},' \
		${WRKSRC}/scripts/scilab.g
	# malloc.h -> stdlib.h conversions
	for file in \
	    examples/intersci-examples/ex6c.c \
	    examples/intersci-examples/ex8c.c \
	    examples/intersci-examples/ex9c.c \
	    examples/interface-tour/pgmsc.c \
	    examples/intersci-examples-so/ex06c.c \
	    examples/intersci-examples-so/ex09c.c \
	    examples/intersci-examples-so/ex08c.c imp/Slatexpr2.c \
	    imp/Slatexprs.c imp/Slpr.c imp/SEpsf.c imp/Slatexpr.c \
	    intersci/intersci.h intersci/intersci-n.h \
	    pvm3/src/imalloc.c routines/calelm/sci_tools.c \
	    routines/comm/messages.c routines/metanet/connex.c \
	    routines/metanet/metanet.c routines/metanet/dmtree.c \
	    routines/metanet/files.c routines/metanet/loadg.c \
	    routines/metanet/paths.c routines/metanet/saveg.c \
	    routines/metanet/show.c routines/metanet/transc.c \
	    routines/metanet/myhsearch.c routines/default/scimem.c \
	    routines/default/Funtab.c routines/sparse/spDefs.h \
	    routines/sun/link.c routines/sun/addinter.c \
	    routines/sun/men_Sutils.c routines/sun/h_help_data.c \
	    routines/xsci/jpc_command.c routines/xsci/jpc_utils.c \
	    routines/xsci/wf_e_edit.c routines/xsci/wf_w_dir.c \
	    routines/xsci/wf_w_file.c routines/xsci/x_button.c \
	    routines/xsci/x_charproc.c routines/xsci/x_screen.c \
	    routines/xsci/x_scrollbar.c routines/xsci/x_test_loop.c \
	    routines/xsci/x_screen.nok.c routines/xsci/jpc_SGraph.c \
	    routines/xsci/jpc_Xloop.c routines/xsci/jpc_coloredit.c \
	    routines/xsci/jpc_SGraph.c.in \
	    routines/libcomm/gest_memoire.c routines/sound/fileio.c \
	    routines/sound/sprintf_ptr.c routines/wsci/winmain.c \
	    routines/wsci/wmprint.c routines/wsci/runscilab.c \
	    routines/wsci/wmtex.c routines/pvm/sci_tools.c \
	    routines/graphics/RecLoad.c routines/graphics/periFig.c \
	    routines/graphics/periPos.c routines/graphics/Math.h \
	    routines/graphics/periGif.c xless/xless.h xmetanet/comm.c \
	    xmetanet/dialog.c xmetanet/file.c xmetanet/graph.c \
	    xmetanet/graphics.c xmetanet/list.c xmetanet/load.c \
	    xmetanet/myhsearch.c xmetanet/name.c xmetanet/save.c; do \
	    ${REINPLACE_CMD} -e \
		's/[<"]malloc.h[>"]/<stdlib.h>/' ${WRKSRC}/$${file}; \
	done

pre-install:
	${FIND} ${WRKSRC} -name \*.orig -delete
	${FIND} ${WRKSRC} -name \*.bak -delete

.include <bsd.port.mk>
