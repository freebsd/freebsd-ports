# Created by: Aaron Landwehr <aaron@snaphat.com>
# $FreeBSD$

PORTNAME=	usrinfo
PORTVERSION=	.10
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	aaron@snaphat.com
COMMENT=	Displays information about a user using either "<br>" or "\n" breaks

LICENSE=	BSD2CLAUSE

USE_BZIP2=	yes

PLIST_FILES=	bin/usrinfo man/man1/usrinfo.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usrinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/usrinfo.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
