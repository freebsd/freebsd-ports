# New ports collection makefile for:	wmwork
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmwork
PORTVERSION=	0.1.0
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://wwwtcs.inf.tu-dresden.de/~godisch/debian/wmwork/
DISTNAME=	wmwork_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes

MAN1=	wmwork.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwork ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwork.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
