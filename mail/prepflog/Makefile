# New ports collection makefile for:   prepflog
# Date created:        14 January 2008
# Whom:                Terry Sposato
#
# $FreeBSD$
#

PORTNAME=	prepflog
PORTVERSION=	0.3
CATEGORIES=	mail
MASTER_SITES=	http://www.gufonero.com/postfix/
EXTRACT_SUFX=	.tgz

MAINTAINER=	terry@sucked-in.com
COMMENT=	Prepares logfiles in a sanitised format for pflogsumm and awstats

PLIST_FILES=	bin/prepflog

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
