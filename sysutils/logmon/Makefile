# New ports collection makefile for:	logmon
# Date created:				12 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	logmon
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edespot.com/plaidhat/code/LogMon/
DISTNAME=	LogMon-${PORTVERSION}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	gslin@ccca.nctu.edu.tw

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/LogMon ${PREFIX}/bin

.include <bsd.port.mk>
