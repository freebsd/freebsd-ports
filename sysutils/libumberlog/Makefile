# New ports collection makefile for:	libumberlog
# Date created:				12 April 2012
# Whom:					czanik@balabit.hu
#
# $FreeBSD$
#

PORTNAME=	libumberlog
PORTVERSION=	0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/algernon/libumberlog/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	CEE-enhanced syslog API

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27
BROKEN=		fails to install umberlog.3

GNU_CONFIGURE=  yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

MAN3=		umberlog.3

.include <bsd.port.mk>
