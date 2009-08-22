# New ports collection makefile for: ns-2
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	2.33
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}nam/${PORTNAME}-2/${PORTVERSION}

MAINTAINER=	lstewart@FreeBSD.org
COMMENT=	Discrete event simulator for networking research

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl

MAN1=		ns.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.4 --with-tk-ver=8.4 --x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
USE_GMAKE=	yes
USE_TK=		84

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/src/local/Tcl-1.0 \\|${LOCALBASE}/include/tclcl \\|g' \
		-e 's|/usr/src/local/Tcl-1.0\"|${LOCALBASE}/lib\"|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${MANPREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${EXAMPLESDIR}

.include <bsd.port.mk>
