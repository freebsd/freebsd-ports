# New ports collection makefile for:    calc
# Version required:     2.9.3t6
# Date created:         3 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.11 1998/06/04 17:13:49 smace Exp $
#

DISTNAME=	calc-2.9.3t6
PKGNAME=	calc-2.9.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/contrib/
EXTRACT_SUFX=	.tar

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty

MAN1=		calc.1
IGNOREFILES=	${DISTFILES}	# "on-the-fly" creation of tarball

pre-install:
	@${MKDIR} ${PREFIX}/lib/calc/help

.include <bsd.port.mk>
