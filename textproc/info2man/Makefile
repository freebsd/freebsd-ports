# New ports collection makefile for: info2man
# Date created:         19 January 2005
# Whom:                 Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	info2man
PORTVERSION=	20040717
CATEGORIES=	textproc
MASTER_SITES=	http://www.cskk.ezoshosting.com/cs/css/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into man pages

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLSCRIPTS=	info2man info2pod

pre-configure:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/info2pod

do-install:
	${INSTALL_SCRIPT} ${PLSCRIPTS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/cs ${DATADIR}

.include <bsd.port.mk>
