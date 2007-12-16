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

LIB_DEPENDS=	ginac-1.3.8:${PORTSDIR}/math/GiNaC

BROKEN=		Does not configure (cannot find GiNaC)
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2008-03-17

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

.include <bsd.port.mk>
