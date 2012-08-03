# New ports collection makefile for:   ezjail
# Date created:        1 September 2005
# Whom:                erdgeist
#
# $FreeBSD$
#

PORTNAME=	ezjail
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/ezjail/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Framework to easily create, manipulate, and run FreeBSD jails

USE_BZIP2=	yes

MAN5=		ezjail.conf.5
MAN7=		ezjail.7
MAN8=		ezjail-admin.8

post-install:
	[ -f ${PREFIX}/etc/${PORTNAME}.conf ] || \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample \
			 ${PREFIX}/etc/${PORTNAME}.conf

.include <bsd.port.mk>
