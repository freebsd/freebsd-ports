# New ports collection makefile for:    woof
# Date created:                         7 July 2009
# Whom:                                 Dereckson <dereckson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	woof
PORTVERSION=	2009.02.27
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.home.unix-ag.org/simon/
DISTNAME=	woof
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dereckson@gmail.com
COMMENT=	Web Offer One File, an ad-hoc single file webserver

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/woof

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/woof ${PREFIX}/bin/woof

.include <bsd.port.mk>
