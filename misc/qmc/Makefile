# ex:ts=8
# New ports collection makefile for:	qmc
# Date created:			Nov 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qmc
PORTVERSION=	0.92b3
CATEGORIES=	misc
MASTER_SITES=	http://qmc.pollaknet.at/program/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/bbeta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quine-McClusky process simplification tool

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/qmc

do-build:
	@cd ${WRKSRC} ; \
	  ${RM} -f *.o ; \
	  ${CXX} ${CXXFLAGS} -I. *.cc -o qmc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmc ${PREFIX}/bin

.include <bsd.port.mk>
