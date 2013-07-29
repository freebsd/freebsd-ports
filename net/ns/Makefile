# Created by: Oscar Bonilla <obonilla@fisicc-ufm.edu>
# $FreeBSD$

PORTNAME=	ns
PORTVERSION=	2.35
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}nam/${PORTNAME}-2/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Discrete event simulator for networking research

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl

USES=		gmake
USE_TK=		85+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} \
		--with-tk-ver=${TK_VER} \
		--x-libraries=${LOCALBASE}/lib \
		--x-includes=${LOCALBASE}/include

WRKSRC=		${WRKDIR}/ns-${PORTVERSION}

MAN1=		ns.1

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,Tcl_GetHashKey,static_cast<char*>&," \
		${WRKSRC}/pushback/ident-tree.h \
		${WRKSRC}/webcache/pagepool.cc
	@${REINPLACE_CMD} -e "/^CFLAGS =/s,$$, -DUSE_INTERP_RESULT," \
		${WRKSRC}/indep-utils/webtrace-conv/dec/Makefile.in \
		${WRKSRC}/indep-utils/webtrace-conv/epa/Makefile.in \
		${WRKSRC}/indep-utils/webtrace-conv/nlanr/Makefile.in \
		${WRKSRC}/indep-utils/webtrace-conv/ucb/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
