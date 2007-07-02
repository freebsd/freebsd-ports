# ex:ts=8
# Ports collection makefile for:	xloops
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xloops-ginac
PORTVERSION=	0.1.3
PORTREVISION=	8
CATEGORIES=	science
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~xloops/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program calculating Feynman diagrams

LIB_DEPENDS=	ginac-1.3.3:${PORTSDIR}/math/GiNaC

USE_GCC=	3.4
USE_GMAKE=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CFLAGS+=	-fpermissive
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2, does not compile with GCC 3.4 against GiNaC compiled with GCC 4.2
.endif

.include <bsd.port.post.mk>
