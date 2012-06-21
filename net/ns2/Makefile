# New ports collection makefile for: ns-2
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	2.35
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}nam/${PORTNAME}-2/${PORTVERSION}
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.tar.gz

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Discrete event simulator for networking research

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl

MAN1=		ns.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER} --x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
USE_GMAKE=	yes
USE_TK=		85+

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
