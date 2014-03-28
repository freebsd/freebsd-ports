# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	cf
PORTVERSION=	1.2.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ee.lbl.gov/ \
		http://www.tux.org//pub/net/ftp.ee.lbl.gov/ \
		http://ftp.riken.go.jp/pub/net/lbl/ \
		http://www.ftpdir.hu/ftp.ee.lbl.gov/
PKGNAMEPREFIX=	lbl-

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Unix time to formated time and date filter

LICENSE=	BSD3CLAUSE

INSTALL_TARGET=	install install-man

PLIST_FILES=	bin/cf \
		man/man1/cf.1.gz

GNU_CONFIGURE=	yes

pre-install:
	@${STRIP_CMD} ${WRKSRC}/cf

.include <bsd.port.mk>
