# New ports collection makefile for: cheatah
# Date created:   11 June 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	cheatah
PORTVERSION=	${SWORD_PORTVERSION}
CATEGORIES=	misc
MASTER_SITES=	${SWORD_MASTER_SITES}
MASTER_SITE_SUBDIR=	${SWORD_MASTER_SIZE_SUBDIR}
DISTNAME=	${SWORD_DISTNAME}

MAINTAINER=	wvengen@stack.nl
COMMENT=	Temporary gtk GUI to the SWORD project

LIB_DEPENDS=	sword.1:${PORTSDIR}/misc/sword

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

PLIST_FILES=	bin/cheatah
WRKSRC=		${WRKDIR}/${DISTNAME}/apps/X11/cheatah

.include "${.CURDIR}/../sword/Makefile.common"

post-patch:
	@${CHMOD} a+x ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/cheatah

.include <bsd.port.mk>
