# New ports collection makefile for:	mbox2mdir
# Date created:		2005-10-30
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	mbox2mdir
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://sageshome.net/downloads/oss/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A mbox to qmail's Maildir converter written in C++

USE_BZIP2=	yes

PLIST_FILES=	bin/mbox2mdir

do-build:
	${CXX} ${CXXFLAGS} ${WRKSRC}/mbox2mdir.cpp -o ${WRKSRC}/mbox2mdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbox2mdir ${PREFIX}/bin

.include <bsd.port.mk>
