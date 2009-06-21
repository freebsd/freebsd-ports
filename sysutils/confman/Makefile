# New ports collection makefile for:   confman
# Date created:        6 May 2009
# Whom:                ccowart@timesinks.net
#
# $FreeBSD$
#

PORTNAME=	confman
PORTVERSION=	1.9.0b
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.timesinks.net/distfiles/

MAINTAINER=	ccowart@timesinks.net
COMMENT=	A revision controlled configuration manager

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		svn:${PORTSDIR}/devel/subversion \
		sudo:${PORTSDIR}/security/sudo \
		greadlink:${PORTSDIR}/sysutils/coreutils

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=/var

MAN5=		confman.conf.5
MAN8=		confadmin.8 confaudit.8 confexport.8 confman.8 confsync.8

.include <bsd.port.mk>
