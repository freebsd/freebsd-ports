# New ports collection makefile for:	dejagnu
# Date created:		12 October 1996
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	dejagnu
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	misc tcl83 tk83
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	dejagnu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated program/system tester

RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		runtest.1

.include <bsd.port.mk>
