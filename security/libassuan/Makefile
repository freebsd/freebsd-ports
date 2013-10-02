# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libassuan
PORTVERSION=	2.1.1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	IPC library used by GnuPG and gpgme

LIB_DEPENDS=	libgpg-error.so:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# Silly, but apparently the only way to get the proper shared lib version number
USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack

INFO=		assuan
PLIST_FILES=	bin/libassuan-config include/assuan.h \
		lib/libassuan.a lib/libassuan.la \
		lib/libassuan.so.0 lib/libassuan.so share/aclocal/libassuan.m4

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
