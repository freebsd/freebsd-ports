# New ports collection makefile for:	makeztxt
# Date created:		Oct 19, 2002
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	makeztxt
PORTVERSION=	1.60
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gutenpalm
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line utility to create GutenPalm's zTXT format databases

PLIST_FILES=	bin/makeztxt
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes

MAKE_ENV+=	USEPOSIX=1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
MAKE_ENV+=	LONG_OPTS=1
.endif

post-patch:
	${REINPLACE_CMD} 's/-O2//' ${WRKSRC}/libztxt/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeztxt ${LOCALBASE}/bin/

.include <bsd.port.post.mk>
