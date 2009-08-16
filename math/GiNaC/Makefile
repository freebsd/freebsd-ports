# ex:ts=8
# New ports collection makefile for:	GiNaC
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GiNaC
PORTVERSION=	1.5.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	stephen@missouri.edu
COMMENT=	A C++ library for symbolic mathematical calculations

LIB_DEPENDS=	cln.6:${PORTSDIR}/math/cln

USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=	ginsh.1 viewgar.1
INFO=	ginac ginac-examples

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
