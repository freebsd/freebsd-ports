# New ports collection makefile for:	majorcool
# Date created:			Wed Aug 13 18:34:14 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	majorcool
PORTVERSION=	1.3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Web Interface to Majordomo


DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${LOCALBASE}/majordomo/majordomo.pl:${PORTSDIR}/mail/majordomo
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
IS_INTERACTIVE=	yes
USE_PERL5=	yes

do-install:
		( cd ${WRKSRC}; ${SH} Configure )

.include <bsd.port.mk>
