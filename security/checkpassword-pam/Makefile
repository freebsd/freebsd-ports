# New ports collection makefile for:	checkpassword-pam
# Date created:				30 september 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	checkpassword-pam
PORTVERSION=	0.99
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	checkpasswd-pam

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Implementation of checkpassword authentication program

GNU_CONFIGURE=	yes

MAN8=		checkpassword-pam.8
PLIST_FILES=	bin/checkpassword-pam

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
