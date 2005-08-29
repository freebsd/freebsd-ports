# New ports collection makefile for:	nail
# Date created:				20 October 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nail
PORTVERSION=	11.25
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	BSD mail utility with MIME extensions

USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SENDMAIL="/usr/sbin/sendmail" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		IPv6="-DHAVE_IPv6_FUNCS"

MAN1=		nail.1
PLIST_FILES=	bin/nail \
		"@unexec if cmp -s %D/etc/nail.rc %D/etc/nail.rc.default; then rm -f %D/etc/nail.rc; fi " \
		"etc/nail.rc.default" \
		"@exec [ -f %B/nail.rc ] || cp %B/%f %B/nail.rc"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nail.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc/nail.rc.default
.if !exists(${PREFIX}/etc/nail.rc)
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc
.endif

.include <bsd.port.mk>
