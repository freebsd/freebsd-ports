# New ports collection makefile for:	gnomehier
# Date created:				2 July 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomehier
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	sobomax@FreeBSD.org

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-fetch:
	@${DO_NADA}

do-install:
	@for dir in `${CAT} ${FILESDIR}/dirlist`; \
	do \
		${MKDIR} ${PREFIX}/$${dir}; \
		${TOUCH} ${PREFIX}/$${dir}/.keep_me; \
	done

.include <bsd.port.mk>
