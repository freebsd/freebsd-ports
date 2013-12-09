# Created by: Serge Gagnon <gagnon__s@videotron.ca>
# $FreeBSD$

PORTNAME=	libutf
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/misc/ \
		http://www.westley.demon.co.uk/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-8 character set support library, including regular expressions

GNU_CONFIGURE=	YES
ALL_TARGET=	tst
MAKE_ARGS=	ETCDIR=${EXAMPLESDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/ure.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/utf.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libutf.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/langcoll.utf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/utf.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/ure.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
