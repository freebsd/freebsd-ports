# New ports collection makefile for:	wmfuzzy
# Date created:			4 August 2002
# Whom:				Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmfuzzy
PORTVERSION=	0.2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.manicai.net/comp/wmfuzzy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adamw@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${PORTNAME}/src
USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmfuzzy ${PREFIX}/bin

.include <bsd.port.mk>
