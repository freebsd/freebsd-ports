# New ports collection makefile for:	gnomehier
# Date created:				2 July 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomehier
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	misc gnome
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	sobomax@FreeBSD.org

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_X_PREFIX=	yes

do-fetch:
	@${DO_NADA}

do-install:
	@for dir in `${CAT} ${FILESDIR}/dirlist`; \
	do \
		${MKDIR} ${PREFIX}/$${dir}; \
		${TOUCH} ${PREFIX}/$${dir}/.keep_me; \
	done
	${TOUCH} -f ${PREFIX}/etc/gconf/gconf.xml.defaults/schemas/apps/%gconf.xml
	@${CHMOD} +x ${PREFIX}/etc/gdm/Sessions/.keep_me

.include <bsd.port.mk>
