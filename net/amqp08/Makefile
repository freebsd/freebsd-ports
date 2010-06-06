# New ports collection makefile for:	amqp08
# Date Created:				2009-07-05
# Whom:					Bruce Simpson
#
# $FreeBSD$
#

PORTNAME=	amqp08
PORTVERSION=	20090705
CATEGORIES=	net
MASTER_SITES=	http://jira.amqp.org/confluence/download/attachments/720900/
DISTNAME=	amqp0-8.xml
EXTRACT_SUFX=
DIST_SUBDIR=	amqp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vendor neutral AMQP 0.8 XML specification

NO_BUILD=	defined

do-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/amqp
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
	    ${PREFIX}/share/amqp

.include <bsd.port.mk>
