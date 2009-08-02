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

LIB_DEPENDS=	ginac-1.4.0:${PORTSDIR}/math/GiNaC

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 autoconf:262 automake:110 \
		libtool:22
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CFLAGS+=	-fpermissive
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
