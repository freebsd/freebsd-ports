# New ports collection makefile for:	playd
# Date created:				Apr 29, 2009
# Whom:					Aldis Berjoza <killasmurf86@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	playd2
PORTVERSION=	2.1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://files.bsdroot.lv/FreeBSD/playd/

MAINTAINER=	aldis@BSDroot.lv
COMMENT=	Very easy to use mplayer Perl wrapper script, with useful features

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LOCALBASE}/${SITE_PERL_REL}/File/Type.pm:${PORTSDIR}/devel/p5-File-Type

CONFLICTS=	playd-1.[0-9]*
PROJECTHOST=	playd
PLIST_FILES=	bin/playd
MAN1=		playd.1

NO_BUILD=	yes
USE_PERL5_RUN=	5.8.9+

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/playd.pl ${PREFIX}/bin/playd
	${INSTALL_MAN} ${WRKSRC}/man/man1/playd.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
