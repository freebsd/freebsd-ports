# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xcdroast.org/download/
DISTNAME=	xcdroast-0.98alpha8

MAINTAINER=	Kai_Allard_Liao@gmx.de

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_IMLIB=	yes

post-install:
	       ${LN} -sf ${PREFIX}/bin/cdrecord ${X11BASE}/lib/xcdroast-0.98/bin/cdrecord
	       ${LN} -sf ${PREFIX}/bin/mkisofs ${X11BASE}/lib/xcdroast-0.98/bin/mkisofs
	       ${LN} -sf ${PREFIX}/bin/cdda2wav ${X11BASE}/lib/xcdroast-0.98/bin/cdda2wav
	       ${LN} -sf ${PREFIX}/bin/readcd ${X11BASE}/lib/xcdroast-0.98/bin/readcd

.include <bsd.port.mk>
