# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	grpn
PORTVERSION=	1.1.2
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://lashwhip.com/grpn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-based reverse polish notation (RPN) calculator

USE_GNOME=	gtk12

ALL_TARGET=

PLIST_FILES=	bin/grpn man/man1/grpn.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grpn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/grpn.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
