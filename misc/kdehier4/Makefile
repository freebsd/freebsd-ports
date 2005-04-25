# New ports collection makefile for:	kdehier
# Date created:				4 May 2003
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kdehier
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	misc kde
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utility port which installs a hierarchy of shared KDE directories

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-fetch:
	@${DO_NADA}

do-install:
	@for dir in `${GREP} -v "^@comment" ${FILESDIR}/dirlist`; \
	do \
		${MKDIR} ${PREFIX}/$${dir}; \
		${TOUCH} ${PREFIX}/$${dir}/.keep_me; \
	done

.include <bsd.port.mk>
