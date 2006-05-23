# New ports collection makefile for:	spfval
# Date created:				22 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	spfval
PORTVERSION=	0.0.1
CATEGORIES=	mail
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A SPF validator

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/spfval

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/spfval ${PREFIX}/bin

.include <bsd.port.mk>
