# New ports collection makefile for:	pwgen2
# Date created:		27 Aug 2005
# Whom:			Andrew Khlebutin <andrey@hm.perm.ru>
#
# $FreeBSD$
#

PORTNAME=	pwgen
PORTVERSION=	2.04
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andrey@hm.perm.ru
COMMENT=	A small, powerful, GPL'ed password generator

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_PERL5_BUILD=yes

CONFLICTS=	pwgen-1*
LATEST_LINK=	pwgen2

MAN1=		pwgen.1
PLIST_FILES=	bin/pwgen

.include <bsd.port.mk>
