# New ports collection makefile for:	autosig
# Date created:				23 April 2001
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autosig
PORTVERSION=	2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.irendi.com/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A random .signature generator with header file included

MAKEFILE=	makefile
PLIST_FILES=	bin/autosig
ALL_TARGET=	${PORTNAME}
USE_REINPLACE=	yes

pre-build:
	${REINPLACE_CMD} -e 's,gcc,${CC} ${CFLAGS},g' ${WRKSRC}/makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
