# New ports collection makefile for:	wmstock
# Version required:	0.06
# Date created:		19 Jun 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	wmstock-0.06
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://mattfischer.com/wmstock/src/ \
		http://www.psn.net/~andrews/wmstock/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/wmstock/src
USE_GMAKE=	yes
MAN1=		wmstock.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmstock ${PREFIX}/bin/wmstock
	@${INSTALL_SCRIPT} ${WRKSRC}/testqt.pl ${PREFIX}/bin/testqt.pl
	@${INSTALL_MAN} ${WRKSRC}/wmstock.1x ${PREFIX}/man/man1/wmstock.1

.include <bsd.port.mk>
