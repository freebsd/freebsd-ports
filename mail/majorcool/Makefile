# New ports collection makefile for:	majorcool
# Date created:			Wed Aug 13 18:34:14 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	majorcool
PORTVERSION=	1.3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.netsw.org/netsw/Network/Mail/Tools/ListManager/majordomo/ \
		ftp://ftp.nhl.nl/pub/unix/MajorDomo/

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_PACKAGE=	"Too many questions"
IS_INTERACTIVE=	yes
USE_PERL5=	yes

do-install:
		( cd ${WRKSRC}; ${SH} Configure )

.include <bsd.port.mk>
