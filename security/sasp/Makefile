# New ports collection makefile for:    sasp
# Date created:        2 September 2004
# Whom:                sviat
#
# $FreeBSD$
#

PORTNAME=	sasp
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~ahze/distfiles/
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	sviat@OpenGEEKS.it
COMMENT=	A tool that permits to use a gateway whatever IP we have

BUILD_DEPENDS=	 ${LOCALBASE}/include/libnet/libnet-types.h:${PORTSDIR}/net/libnet-devel

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/sasp

.include <bsd.port.mk>
