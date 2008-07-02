# New ports collection makefile for:   ezjail
# Date created:        1 September 2005
# Whom:                erdgeist
#
# $FreeBSD$
#

PORTNAME=	ezjail
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/ezjail/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	A framework to easily create, manipulate and run FreeBSD jails

USE_BZIP2=	yes

MAN1=		ezjail-admin.1
MAN5=		ezjail.5 ezjail.conf.5

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 600000 )
IGNORE=	nullfs in FreeBSD releases before 6.0 is considered unstable
.endif

.include <bsd.port.post.mk>
