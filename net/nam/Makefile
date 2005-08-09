# New ports collection makefile for: nam
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	nam
PORTVERSION=	1.11
#PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTNAME=	nam-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Animation tool for network simulation traces

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

MAN1=		nam.1
MANCOMPRESSED=	no

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.4 --with-tk-ver=8.4
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	# empty

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,friend Queue,friend class Queue,' ${WRKSRC}/queue.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ex/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
