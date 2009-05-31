# New ports collection makefile for:	tinymce
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	tinymce
PORTVERSION=	2.1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	tinymce_2_1_3
EXTRACT_SUFX=	.tgz

MAINTAINER=	nick@foobar.org
COMMENT=	An open source Javascript HTML WYSIWYG editor for web sites

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	YES
NO_LATEST_LINK=	YES

do-install:
	${INSTALL} -d -m 0755 ${WWWDIR}
	(cd ${WRKSRC} && ${FIND} . -not -name .PLIST.mktmp -not -name '.*_done.*' -not -name pkg-install | \
		${CPIO} -pdmu -R${WWWOWN}:${WWWGRP} ${WWWDIR})

.include <bsd.port.mk>
