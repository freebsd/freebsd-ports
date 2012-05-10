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

.if ${OSVERSION} < 800000
BROKEN=		Fails to install umberlog.3 under 7.X.
.endif

GNU_CONFIGURE=  yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

MAN3=		umberlog.3

.include <bsd.port.mk>
