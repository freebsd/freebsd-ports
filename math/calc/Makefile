# New ports collection makefile for:    calc
# Version required:     2.9.3t6
# Date created:         3 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1997/08/15 18:54:17 jmz Exp $
#

DISTNAME=	calc-2.9.3t6
PKGNAME=	calc-2.9.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/contrib/

MAINTAINER=	jmz@FreeBSD.org

MAN1=		calc.1
IGNOREFILES=	${DISTFILES}	# "on-the-fly" creation of tarball

pre-patch:
	@cd ${WRKDIR} && mv pub/bsd-sources/4.4BSD-Lite/usr/src/contrib/calc-2.9.3t6 .

pre-install:
	@${MKDIR} ${PREFIX}/lib/calc/help

.include <bsd.port.mk>
