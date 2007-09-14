# Ports collection makefile for:  source-highlight
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	source-highlight
PORTVERSION=	2.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	src-highlite

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS= LDFLAGS=-L${LOCALBASE}/lib CPPFLAGS=-I${LOCALBASE}/include
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS="${NOPORTDOCS}"
.endif

USE_GMAKE=	yes

MAN1=	source-highlight.1
INFO=	source-highlight

.include <bsd.port.mk>
