# New ports collection makefile for:	libassuan
# Date created:		2004-04-19
# Whom:			Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libassuan
PORTVERSION=	1.0.3
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	IPC library used by GnuPG and gpgme

LIB_DEPENDS+=	pth.20:${PORTSDIR}/devel/pth

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INFO=		assuan

CFLAGS+=	-I${LOCALBASE}/include/pth

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
