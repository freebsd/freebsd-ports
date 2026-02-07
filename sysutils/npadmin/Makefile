PORTNAME=	npadmin
PORTVERSION=	0.8.7
PORTREVISION=	2
CATEGORIES=	sysutils print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNMP based command line network printer management tool
WWW=		https://npadmin.sourceforge.net/

USES=		compiler
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

PLIST_FILES=	bin/npadmin share/man/man1/${PORTNAME}.1.gz

pre-configure:
	${RM} ${WRKSRC}/getopt.h ${WRKSRC}/getopt1.c

.include <bsd.port.mk>
