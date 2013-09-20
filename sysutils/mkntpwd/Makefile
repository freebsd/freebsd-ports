# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	mkntpwd
PORTVERSION=	1.0
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ldaputils/Contrib/mkntpwd
DISTNAME=	${PORTNAME}

MAINTAINER=	pcTA@cs.nctu.edu.tw
COMMENT=	A utility to create Samba password hashes

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/mkntpwd

LICENSE=	GPLv2 BSD
LICENSE_COMB=	multi

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkntpwd ${PREFIX}/bin

.include <bsd.port.mk>
