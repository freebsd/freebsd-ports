# New ports collection makefile for:	kmess
# Date created:			21 June 2002
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	kmess
PORTVERSION=	1.5.p.1
PORTREVISION=	3
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p./pre/}

MAINTAINER=	freebsd-ports@club-internet.fr
COMMENT=	MSN Messenger Client for KDE3

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

post-patch:
	@${TOUCH} -t 200510070000 ${WRKSRC}/admin/cvs.sh
	@${TOUCH} -t 200510070001 ${WRKSRC}/Makefile.am.in
	@${TOUCH} -t 200510070002 ${WRKSRC}/subdirs
	@${TOUCH} -t 200510070003 ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
