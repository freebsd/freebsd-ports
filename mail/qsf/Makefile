# New ports collection makefile for: qsf
# Date created:		15 January 2004
# Whom:			liamfoy@sepulcrum.org
#
# $FreeBSD$
#

PORTNAME=	qsf
PORTVERSION=	0.9.18
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qsf
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	liamfoy@sepulcrum.org
COMMENT=	A small fast spam filter intended to be used with procmail

GNU_CONFIGURE=	yes
USE_BZIP2=	yes

MAN1=		qsf.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/qsf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qsf ${PREFIX}/bin/qsf
	${INSTALL_MAN} ${WRKSRC}/doc/quickref.1 ${MAN1PREFIX}/man/man1/qsf.1

.include <bsd.port.mk>
