# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	lmmon
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Display information gathered from MB power management controller

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
MAN8=		lmmon.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/lmmon

LICENSE=	BSD

FIXFILES=	configure configure.in lmmon.c

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,machine/smb.h,dev/smbus/smb.h,' \
		${FIXFILES:S,^,${WRKSRC}/,}

.include <bsd.port.mk>
