# New ports collection makefile for:	tkinfo
# Version required:     1.5
# Date created:         16 Jan 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.12 1997/04/20 13:19:35 wosch Exp $
#

DISTNAME=	tkinfo-1.5
CATEGORIES=	misc tk41
MASTER_SITES=	http://www.math.ucsb.edu/~boldt/tkinfo/ \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	tg@freebsd.org

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin

.include <bsd.port.mk>
