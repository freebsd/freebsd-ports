# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libassuan
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	IPC library used by GnuPG and gpgme

LIB_DEPENDS=	libgpg-error.so:${PORTSDIR}/security/libgpg-error

GNU_CONFIGURE=	yes
USES=		libtool:keepla tar:bzip2
USE_LDCONFIG=	yes

INFO=		assuan
PLIST_FILES=	bin/libassuan-config include/assuan.h \
		lib/libassuan.la lib/libassuan.so lib/libassuan.so.0 \
		lib/libassuan.so.0.4.1 share/aclocal/libassuan.m4

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
