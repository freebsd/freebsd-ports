# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	npadmin
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	sysutils print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNMP based command line network printer management tool

USES=		compiler
GNU_CONFIGURE=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

PLIST_FILES=	bin/npadmin man/man1/${PORTNAME}.1.gz

pre-configure:
	${RM} ${WRKSRC}/getopt.h ${WRKSRC}/getopt1.c

.include <bsd.port.mk>
