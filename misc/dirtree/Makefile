# ex:ts=8
# New ports collection makefile for:	dirtree
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dirtree
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://home.pages.at/kingleo/development/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A command line tool for displaying directory trees

LIB_DEPENDS=	LeoArg.2:${PORTSDIR}/devel/leoarg \
		intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

MAN1=	dirtree.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

.include <bsd.port.post.mk>
