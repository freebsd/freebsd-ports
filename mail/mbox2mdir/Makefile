# $FreeBSD$

PORTNAME=	mbox2mdir
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	http://sageshome.net/downloads/oss/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Mbox to qmail's Maildir converter written in C++

LICENSE=	GPLv2

USES=	tar:bzip2

PLIST_FILES=	bin/mbox2mdir

do-build:
	${CXX} ${CXXFLAGS} ${WRKSRC}/mbox2mdir.cpp -o ${WRKSRC}/mbox2mdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbox2mdir ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
