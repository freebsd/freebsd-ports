# New ports collection makefile for: 	pipemeter
# Date created:			2003-12-02
# Whom:				Len Sassama
#
# $FreeBSD$
#

PORTNAME=	pipemeter
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ports.abditum.com/pipemeter/ \
		http://spamaps.org/files/pipemeter/

MAINTAINER=	rabbi@abditum.com
COMMENT=	A tool for displaying pipe status information

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
CONFIGURE_ENV=		PREFIX="${PREFIX}"

MAN1=		pipemeter.1
PLIST_FILES=	bin/pipemeter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipemeter ${PREFIX}/bin/pipemeter
	${INSTALL_MAN} ${WRKSRC}/pipemeter.1 ${PREFIX}/man/man1/pipemeter.1

.include <bsd.port.mk>
