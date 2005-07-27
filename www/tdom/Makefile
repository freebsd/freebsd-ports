# New ports collection makefile for:	tDOM
# Date created:				July 2005
# Whom:					Aldert Nooitgedagt
#
# $FreeBSD$
#

PORTNAME=	tDOM
PORTVERSION=	0.8.0
CATEGORIES=	www
MASTER_SITES=	http://www.tdom.org/files/

MAINTAINER=	aldert@nooitgedagt.net
COMMENT=	High performance XML data processing with Tcl (ARGS for OpenACS)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/unix
TDOMBASE=	${PREFIX}/lib/tdom${PORTVERSION}

LIB_DEPENDS+=	tcl84.1:${PORTSDIR}/lang/tcl84-thread

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--enable-threads --disable-tdomalloc --with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tclinclude=${LOCALBASE}/include/tcl8.4  --prefix=${PREFIX}

INSTALLS_SHLIB=	YES
LDCONFIG_DIRS+=	${TDOMBASE}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-configure:
	@${ECHO_CMD}
	@${ECHO_CMD} "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_CMD} " Please make sure that you either have lang/tcl84-thread or "
	@${ECHO_CMD} " no tcl84 installed before you add this port "
	@${ECHO_CMD} "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_CMD}

post-configure:
	@if ${GREP} -qs 'enable-threads requested, but attempting building against' ${WRKSRC}/config.log ; then \
		${ECHO_CMD} "" && \
		${ECHO_CMD} " =====================================================" && \
		${ECHO_CMD} " You need ${PORTSDIR}/lang/tcl84-thread but you appear " && \
		${ECHO_CMD} " to have the non-threaded TCL version installed." && \
		${ECHO_CMD} " =====================================================" && \
		${ECHO_CMD} "" && \
		${FALSE}; \
	fi

MANN=		dom.n domDoc.n domNode.n expat.n expatapi.n tdomcmd.n tnc.n
MANCOMPRESSED=	no

.include <bsd.port.mk>
