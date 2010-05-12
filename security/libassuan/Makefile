# New ports collection makefile for:	libassuan
# Date created:		2004-04-19
# Whom:			Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libassuan
PORTVERSION=	1.0.5
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	IPC library used by GnuPG and gpgme

LIB_DEPENDS+=	pth.20:${PORTSDIR}/devel/pth

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INFO=		assuan
PLIST_FILES=	bin/libassuan-config include/assuan.h lib/libassuan-pth.a \
		lib/libassuan.a share/aclocal/libassuan.m4

CFLAGS+=	-I${LOCALBASE}/include/pth

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.post.mk>
