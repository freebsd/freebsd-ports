# New ports collection makefile for:   Scilab
# Version required:    2.4.1
# Date created:        13 June 1997
# Whom:                paulo@isr.uc.pt
#
# $FreeBSD$
#

DISTNAME=	scilab-${SCILAB_VER}
PKGNAME=	Scilab-${SCILAB_VER}
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	paulo@isr.uc.pt

RUN_DEPENDS=	pvm:${PORTSDIR}/net/pvm	\
		xless:${PORTSDIR}/misc/xless

SCILAB_VER=	2.4.1
PLIST_SUB+=	SCILAB_VER=${SCILAB_VER}

NO_CDROM=	"Don't sell for profit."
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAKE_ENV=	SCIDIR=${PREFIX}/lib/X11/$(DISTNAME)

pre-install:
	@(cd $(WRKSRC); ${RM} -rf Win95-util *.orig)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
