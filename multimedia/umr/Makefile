# New ports collection makefile for:	umr
# Date created:				19 October 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	umr
PORTVERSION=	0.3
CATEGORIES=	multimedia
MASTER_SITES=	http://pages.cthome.net/chrismp/umr/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Unreal Media Ripper

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
