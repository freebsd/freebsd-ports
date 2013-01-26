# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	tinymce
PORTVERSION=	2.1.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TinyMCE/${PORTVERSION}
DISTNAME=	tinymce_2_1_3
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	YES
NO_LATEST_LINK=	YES

do-install:
	${INSTALL} -d -m 0755 ${WWWDIR}
	(cd ${WRKSRC} && ${FIND} . -not -name .PLIST.mktmp -not -name '.*_done.*' -not -name pkg-install | \
		${CPIO} -pdmu -R${WWWOWN}:${WWWGRP} ${WWWDIR})

.include <bsd.port.mk>
