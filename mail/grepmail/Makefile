# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION=	4.45
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

MAINTAINER=	jedgar@FreeBSD.org

USE_PERL5=	yes

MAN1=		grepmail.1

do-configure:
		@${PERL} -pi.orig -e 's|_PERL_|${PERL}|' ${WRKSRC}/grepmail
		@cd ${WRKSRC} && ${PERL} Makefile.PL

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/grepmail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/blib/man1/grepmail.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
