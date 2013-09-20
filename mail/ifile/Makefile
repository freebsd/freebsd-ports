# Created by: David Bushong <david+ports@bushong.net>
# $FreeBSD$

PORTNAME=	ifile
PORTVERSION=	1.3.8
CATEGORIES=	mail textproc
MASTER_SITES=	http://people.csail.mit.edu/jrennie/ifile/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application of machine learning to e-mail filtering

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

MAN1=		ifile.1
PLIST_FILES=	bin/ifile

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
