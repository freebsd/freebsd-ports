# New ports collection makefile for:   dejasearch
# Version required:    1.6.3
# Date created:        15 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	dejasearch163
PKGNAME=	dejasearch-1.6.3
CATEGORIES=	news
MASTER_SITES=	http://homemade.hypermart.net/dejasearch/ \
		http://homemade.virtualave.net/dejasearch/ \
		http://www.freebsd.org/~kris/distfiles/

MAINTAINER=	kris@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

MAN1=		dejasearch.1

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dejasearch ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dejasearch.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
