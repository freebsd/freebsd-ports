# New ports collection makefile for:   anacron
# Date created:        15 Jul 2003
# Whom:                Derik van Zuetphen <dz@426.ch>
#
# $FreeBSD$
#

PORTNAME=	anacron
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anacron

MAINTAINER=	dz@426.ch
COMMENT=	Schedules periodic jobs on systems that are not permanently up

MAN8=		anacron.8
MAN5=		anacrontab.5
USE_GMAKE=	yes

post-install:
	${CAT} pkg-message
	${STRIP_CMD} ${PREFIX}/sbin/anacron

.include <bsd.port.mk>
