# New ports collection makefile for:	listmanager
# Date created:				29 Dec 1999
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	listmanager
PORTVERSION=	2.107
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.listmanager.org/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.freebsd35
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} help.tar.gz listmanager.8 ack

MAINTAINER=	gshapiro@FreeBSD.org

FORBIDDEN=	"Security problem.  New version due shortly."

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}
MAN8=		listmanager.8

pre-patch:
	(cd ${WRKSRC} && ${TAR} xfz help.tar.gz)

do-install:
	@${MKDIR} ${PREFIX}/etc
	@${MKDIR} ${PREFIX}/share/listmanager/db
	@${MKDIR} ${PREFIX}/share/listmanager/files
	@${MKDIR} ${PREFIX}/share/listmanager/help
	@${MKDIR} ${PREFIX}/share/listmanager/synchfiles
	${TOUCH} ${PREFIX}/etc/listmanager.cf
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/listmanager/help
	${INSTALL_MAN} ${WRKSRC}/listmanager.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/sbin/listmanager
	${CHMOD} 4510 ${PREFIX}/sbin/listmanager

.include <bsd.port.mk>
