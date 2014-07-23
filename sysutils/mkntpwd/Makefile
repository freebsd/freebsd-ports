# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	mkntpwd
PORTVERSION=	1.0
CATEGORIES=	sysutils net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	ldaputils/Contrib/mkntpwd
DISTNAME=	${PORTNAME}

MAINTAINER=	pcTA@cs.nctu.edu.tw
COMMENT=	Utility to create Samba password hashes

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/mkntpwd

LICENSE=	GPLv2 BSD
LICENSE_COMB=	multi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkntpwd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
