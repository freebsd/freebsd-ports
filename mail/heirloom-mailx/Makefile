# New ports collection makefile for:	nail
# Date created:		20 October 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nail
PORTVERSION=	11.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD mail utility with MIME extensions

USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SENDMAIL="/usr/sbin/sendmail"

MAN1=		nail.1
PLIST_FILES=	bin/nail etc/nail.rc

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_ICONV -DHAVE_IPv6_FUNCS
LDFLAGS=	-L${LOCALBASE}/lib -liconv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nail ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/nail.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
