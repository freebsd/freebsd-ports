# ex:ts=8
# New ports collection makefile for:	gexpr
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gexpr
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/math/calc

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A shell calculator

USE_GETOPT_LONG=yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		gexpr.1
PLIST_FILES=	bin/gexpr

.include <bsd.port.mk>
