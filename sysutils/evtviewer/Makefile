# New ports collection makefile for:    evtViewer
# Date created:		Sat Sep 01 09:30:00 UTC 2006
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	evtViewer
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/evtViewer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	PERL-based Event viewer

LICENSE=	GPLv2

USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/evtViewer

# Just copy the script
do-install:
	${CP} ${WRKSRC}/evtViewer ${PREFIX}/bin

.include <bsd.port.mk>
