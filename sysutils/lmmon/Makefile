# New ports collection makefile for:	lmmon
# Date created:				24 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	lmmon
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fxp.org/~jedgar/lmmon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display information gathered from MB power management controller

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
MAN8=		lmmon.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/lmmon

FIXFILES=	configure configure.in lmmon.c

post-patch:
	@${REINPLACE_CMD} -e 's,machine/smb.h,dev/smbus/smb.h,' \
		${FIXFILES:S,^,${WRKSRC}/,}

.include <bsd.port.mk>
