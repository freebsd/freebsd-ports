# ex:ts=8
# Ports collection makefile for:	libtre
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.3.2
CATEGORIES=	textproc
MASTER_SITES=	http://kouli.iki.fi/~vlaurika/libtre/

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500028
IGNORE=		"need wchar support"
.endif

.include <bsd.port.post.mk>
