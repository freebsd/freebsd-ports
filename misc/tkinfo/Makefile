# New ports collection makefile for:	tkinfo
# Version required:     1.2
# Date created:         16 Jan 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.11 1997/03/06 10:50:29 tg Exp $
#

DISTNAME=	tkinfo-1.2
CATEGORIES=	misc tk41
MASTER_SITES=	http://www.math.ucsb.edu/~boldt/tkinfo/ \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	tg@freebsd.org

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin

.include <bsd.port.mk>
