# New ports collection makefile for:   Scilab
# Date created:        13 June 1997
# Whom:                paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	Scilab
PORTVERSION=	2.4.1
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/
DISTNAME=	scilab-${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	paulo@isr.uc.pt

RUN_DEPENDS=	pvm:${PORTSDIR}/net/pvm	\
		xless:${PORTSDIR}/misc/xless

PLIST_SUB=	SCILAB_VER=${PORTVERSION}

NO_CDROM=	"Don't sell for profit."
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAKE_ENV=	SCIDIR=${PREFIX}/lib/X11/$(DISTNAME)

pre-install:
	@(cd $(WRKSRC); ${RM} -rf Win95-util *.orig)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
