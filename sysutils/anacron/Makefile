# New ports collection makefile for:   anacron
# Date created:        15 Jul 2003
# Whom:                Derik van Zuetphen <dz@426.ch>
#
# $FreeBSD$
#

PORTNAME=	anacron
PORTVERSION=	2.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anacron

MAINTAINER=	dz@426.ch
COMMENT=	Schedules periodic jobs on systems that are not permanently up

MAN8=		anacron.8
MAN5=		anacrontab.5
USE_GMAKE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	${CAT} ${PKGMESSAGE}
	${STRIP_CMD} ${PREFIX}/sbin/anacron

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

.include <bsd.port.mk>
