# ex:ts=8
# Ports collection makefile for:	xloops
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xloops-ginac
PORTVERSION=	0.1.3
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~xloops/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program calculating Feynman diagrams

LIB_DEPENDS=	ginac-1.3.1:${PORTSDIR}/math/GiNaC

USE_GCC=	3.4
USE_GNOME=	gnometarget lthack
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CFLAGS+=	-O0
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600006
BROKEN=		"Does not compile on FreeBSD >= 6.x"
.endif

.include <bsd.port.post.mk>
