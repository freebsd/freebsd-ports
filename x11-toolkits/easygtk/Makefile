# New ports collection makefile for:	easygtk
# Date created:				3 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	easygtk
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.linsupport.com/sw/ \
		http://www.linuxbox.com/~drow/EasyGTK/
MASTER_SITE_SUBDIR=	sobomax
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper library for GTK+ which provides simplified GUI API

EXTRACT_BEFORE_ARGS=	# it's intentionally left blank
EXTRACT_CMD=	${CAT}	# not quite `extract', but who cares? ;)

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
INSTALLS_SHLIB=	yes
MAKE_ENV=	MKDIR="${MKDIR}" \
		LN="${LN}"

.include <bsd.port.mk>
