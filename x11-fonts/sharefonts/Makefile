# New ports collection makefile for:    sharefonts
# Date created:         Thu Mar 26 04:50:00 PST 1998
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sharefonts
PORTVERSION=	0.10
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of shareware ATM fonts from the CICA archives

RESTRICTED=	"Shareware.  Cannot be distributed w/o prior authorization."

NO_BUILD=	yes

USE_X_PREFIX=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/sharefont
	${CP} ${WRKDIR}/sharefont/* ${PREFIX}/lib/X11/fonts/sharefont
	${CHMOD} 755 ${PREFIX}/lib/X11/fonts/sharefont
	${CHMOD} 644 ${PREFIX}/lib/X11/fonts/sharefont/*

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.mk>
