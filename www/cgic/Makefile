# New ports collection makefile for:	libcgic
# Date created:				27 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cgic
PORTVERSION=	1.07
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	${FILESDIR}/Makefile.lib
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/cgic
	${INSTALL_DATA} ${WRKSRC}/capture.c ${PREFIX}/share/examples/cgic
	${INSTALL_DATA} ${WRKSRC}/cgictest.c ${PREFIX}/share/examples/cgic
	@${MKDIR} ${PREFIX}/share/doc/cgic
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/cgic
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/cgic
.endif

.include <bsd.port.mk>
