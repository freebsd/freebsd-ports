# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	netrik
# Date created:		2002-12-23
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netrik
PORTVERSION=	1.2.0
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	freebsd-ports@FreeBSD.org

LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-Wl,-rpath,${LOCALBASE}/lib
LIBS=		-L${LOCALBASE}/lib -lgnugetopt
CONFIGURE_ENV+=	CPPFLAGS="${CPPLAGS}" LIBS="${LIBS}" #LDFLAGS="${LDFLAGS}"

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include "${.CURDIR}/manpages.mk"

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>

#EOF
