# New ports collection makefile for:	diskusage
# Version required:	1.00
# Date created:		23 August 1999
# Whom:			maske
#
# $Id$
#

DISTNAME=	diskusage-1.00
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.intsyst.com/pub/FreeBSD/distfiles/

MAINTAINER=	maske@intsyst.com

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400004
BROKEN=		requires libg++.so.4 to run
.endif

MAN1=		diskusage.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/diskusage
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/diskusage.1.gz ${PREFIX}/man/man1

.include <bsd.port.post.mk>
