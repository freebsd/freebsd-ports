# New ports collection makefile for:	iograph
# Date created:				28 September 2007
# Whom:					Markus Dolze
#
# $FreeBSD$
#

PORTNAME=	iograph
PORTVERSION=	0.9.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/iograph

MAINTAINER=	bsdfan@nurfuerspam.de
COMMENT=	Creates HTML statistics of network transfer

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/iograph \
		%%DATADIR%%/in.gif \
		%%DATADIR%%/out.gif \
		%%DATADIR%%/iograph.gif
PLIST_DIRS=	%%DATADIR%%

GNU_CONFIGURE=	yes

MAN8=		iograph.8

.include <bsd.port.mk>
