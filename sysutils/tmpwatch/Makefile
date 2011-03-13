# New ports collection makefile for:	tmpwatch
# Date created:			Feb 20, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	tmpwatch
PORTVERSION=	2.10.1
CATEGORIES=	sysutils
MASTER_SITES=	http://fedorahosted.org/releases/t/m/tmpwatch/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A utility for removing files based on when they were last accessed

USE_BZIP2=	yes

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

MAN8=		tmpwatch.8
PLIST_FILES=	sbin/tmpwatch

post-patch:
	@${REINPLACE_CMD} -E "s/^#include.+mntent.h.+//g" ${WRKSRC}/tmpwatch.c

.include <bsd.port.mk>
