# New ports collection makefile for:	sambasentinel
# Date created:				Thu Jul  5 16:41:21 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	sambasentinel
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://kling.mine.nu/files/
DISTNAME=	SambaSentinel-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	SambaSentinel is a gtk-frontend to smbstatus with additional features

RUN_DEPENDS=	jags:${PORTSDIR}/net/jags

PLIST_FILES=	bin/SambaSentinel
WRKSRC=		${WRKDIR}/SambaSentinel
USE_GMAKE=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
ALL_TARGET=	SambaSentinel

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/SambaSentinel ${PREFIX}/bin

.include <bsd.port.mk>
