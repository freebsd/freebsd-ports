# New ports collection makefile for:	playd
# Date created:				Apr 29, 2009
# Whom:					Aldis Berjoza <killasmurf86@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	playd2
PORTVERSION=	2.0.6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	killasmurf86@gmail.com
COMMENT=	Very easy to use mplayer Perl wrapper script, with useful features

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LOCALBASE}/${SITE_PERL_REL}/File/Type.pm:${PORTSDIR}/devel/p5-File-Type

CONFLICTS=	playd-1.[0-9]*
PROJECTHOST=	playd
PLIST_FILES=	bin/playd
MAN1=		playd.1
WRKSRC=		${WRKDIR}/playd2

NO_BUILD=	yes
USE_PERL5_RUN=	5.8.9+

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/playd.pl ${PREFIX}/bin/playd
	${INSTALL_MAN} ${WRKSRC}/playd.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
