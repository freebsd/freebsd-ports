# Created by: James Flemer <jflemer@alum.rpi.edu>
# $FreeBSD$

PORTNAME=	l2a
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	http://heim.ifi.uio.no/~gisle/enjoy/
DISTNAME=	l2a

MAINTAINER=	jflemer@alum.rpi.edu
COMMENT=	L2a - LaTeX to ASCII converter

USES=		zip

WRKSRC=		${WRKDIR}
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_MAN="${INSTALL_MAN}"

MAN1=		l2a.1
PLIST_FILES=	bin/l2a

NO_STAGE=	yes
.include <bsd.port.mk>
