# New ports collection makefile for:   dejasearch
# Date created:        15 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dejasearch
PORTVERSION=	1.8.6
CATEGORIES=	news
MASTER_SITES=	http://homemade.hypermart.net/dejasearch/ \
		http://homemade.virtualave.net/dejasearch/

MAINTAINER=	kris@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

MAN1=		dejasearch.1

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dejasearch ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dejasearch.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
