# New ports collection makefile for: rdate
# Date created:         19980128
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#

PORTNAME=	rdate
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www3.cons.org/freebsd-distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cracauer

MAINTAINER=	cracauer@cons.org
COMMENT=	Sets the clock of the local host to the time of another host

MAN8=		rdate.8
PLIST_FILES=	sbin/rdate

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdate ${PREFIX}/sbin/.
	${INSTALL_MAN} ${WRKSRC}/rdate.8 ${PREFIX}/man/man8/.

.include <bsd.port.mk>
