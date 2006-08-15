# New ports collection makefile for:	varnish
# Date created:				2006-08-11
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	varnish
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	des@FreeBSD.org
COMMENT=	The Varnish high-performance HTTP accelerator

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

MAN1=		varnishd.1 varnishlog.1 varnishncsa.1 varnishstat.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
