# New ports collection makefile for:    evtViewer
# Date created:		Sat Sep 01 09:30:00 UTC 2006
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	evtViewer
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://contribs.martymac.com/evtViewer/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
EXTRACT_SUFX=	.tgz

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	PERL-based Event viewer

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/evtViewer

# Just copy the scripts
do-install:
	${CP} ${WRKSRC}/evtViewer ${PREFIX}/bin

.include <bsd.port.mk>
