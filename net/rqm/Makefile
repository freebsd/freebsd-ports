# New ports collection makefile for:	rqm
# Date created:		30 January 2000
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	rqm
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net mbone tk
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rqm/1.0.0/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A graphical RTP quality monitor

DEPRECATED=	Unmaintained, anachronistic, mail freebsd-ports@FreeBSD.org or ${MAINTAINER} if interested
EXPIRATION=	2011-06-30

USE_TK=		yes
LIB_DEPENDS=	uclmmbase:${PORTSDIR}/devel/uclmmbase

WRKSRC=		${WRKDIR}/rqm/

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX} X11BASE=${LOCALBASE}

ALL_TARGET=	rqm
PLIST_FILES=	bin/rqm
PORTDOCS=	README
CONFIGURE_ENV+=	LOCALBASE='${LOCALBASE}' X11BASE='${X11BASE}'
EXTRACT_AFTER_ARGS=|${TAR} -xpf - rqm

post-patch:
	${REINPLACE_CMD} -e 's/%TK_VER%/${TK_VER}/g'	\
	    -e 's/%TCL_VER%/${TCL_VER}/g'	\
	    -e 's/%TK_DVER%/${TK_VER:S/.//}/g'	\
	    -e 's/%TCL_DVER%/${TCL_VER:S/.//}/g'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rqm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
