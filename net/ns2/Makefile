# New ports collection makefile for: ns-2
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	2.29
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTNAME=	ns-src-${PORTVERSION}

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	Discrete event simulator for networking research

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
RUN_DEPENDS=	${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84

MAN1=		ns.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/ns-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.4 --with-tk-ver=8.4
MAKE_ARGS+=	"LDFLAGS=${LDFLAGS}"

ALL_TARGET=

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/src/local/Tcl-1.0 \\|${LOCALBASE}/include/tclcl \\|g' \
		-e 's|/usr/src/local/Tcl-1.0\"|${LOCALBASE}/lib\"|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${PREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${EXAMPLESDIR}

.include <bsd.port.post.mk>
