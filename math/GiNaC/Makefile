# ex:ts=8
# New ports collection makefile for:	GiNaC
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GiNaC
PORTVERSION=	1.3.6
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for symbolic mathematical calculations

LIB_DEPENDS=	cln.4:${PORTSDIR}/math/cln

USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes

MAN1=	ginac-config.1 ginsh.1 viewgar.1
INFO=	ginac

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/tutorial/ginac.info*

.include <bsd.port.post.mk>
