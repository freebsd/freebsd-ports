# New ports collection makefile for:   Scilab
# Version required:    2.3
# Date created:        13 June 1997
# Whom:                paulo@isr.uc.pt
#
# $FreeBSD$
#

DISTNAME=	scilab-2.3.1
PKGNAME=	Scilab-2.3.1
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	paulo@isr.uc.pt

RUN_DEPENDS=    xless:${PORTSDIR}/misc/xless

BROKEN=		package

NO_CDROM=	"Don't sell for profit."
WRKSRC=		${WRKDIR}/scilab-2.3
HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes

SCIDIR= ${X11BASE}/lib/X11/scilab

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
