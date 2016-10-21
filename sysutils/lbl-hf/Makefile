# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	hf
PORTVERSION=	1.7
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ee.lbl.gov/ \
		http://www.mmnt.net/db/0/3/ftp.ee.lbl.gov/
PKGNAMEPREFIX=	lbl-

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Address to hostname filter

LICENSE=	BSD3CLAUSE

CONFLICTS=	hf-[0-9]*

PLIST_FILES=	bin/hf \
		man/man1/hf.1.gz

GNU_CONFIGURE=	yes

# Only install hf
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hf.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
