# ex:ts=8
#
# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=		phoenix
PORTVERSION=		0.3.20021021
PORTREVISION=		0
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alane

MAINTAINER=	alane@freebsd.org # will change to trevor@ soon

.if !defined(RING_OF_FIRE)
.undef NO_IGNORE
BORKED=		This is a work in progress.
BROKEN=		${BORKED}
FORBIDDEN=	${BORKED}
.endif # !defined(RING_OF_FIRE)

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOCONF_VER=	213
GNU_CONFIGURE=		yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>

#EOF
