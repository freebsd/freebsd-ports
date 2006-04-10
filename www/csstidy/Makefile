# ex:ts=8
# Ports collection makefile for:	csstidy
# Date created:			Apr 9, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csstidy
PORTVERSION=	1.1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	An opensource CSS parser and optimiser

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/csstidy

do-build:
	@cd ${WRKSRC} && ${CXX} ${CXXFLAGS} *.cpp -o ${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
