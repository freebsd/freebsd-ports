# New ports collection makefile for:	lopster
# Date created:		19 Oct 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	lopster
PORTVERSION=	0.9.7.2
CATEGORIES=	audio
DISTNAME=	${PORTNAME}-${PORTVERSION}
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

post-extract:
.for i in aclocal.m4 stamp-h.in Makefile.in configure src/Makefile.in
	${TOUCH} ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
