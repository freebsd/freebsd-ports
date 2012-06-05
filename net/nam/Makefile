# New ports collection makefile for: nam
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	nam
PORTVERSION=	1.12
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTNAME=	nam-src-${PORTVERSION}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Animation tool for network simulation traces

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
LIB_DEPENDS=	otcl.1:${PORTSDIR}/lang/otcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	xmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER} --x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
USE_GMAKE=	yes
USE_TK=		85+
ALL_TARGET=	${PORTNAME}

MAN1=		nam.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/src/local/Tcl-1.0|${LOCALBASE}/include/tclcl|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|const = NULL|const = 0|g' ${WRKSRC}/agent.h
	@${REINPLACE_CMD} -e 's|friend Queue|friend class Queue|g' ${WRKSRC}/queue.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ex/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
