# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION=	4.70
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

PERL_CONFIGURE=	yes

MAN1=		grepmail.1

post-patch:
	@${PERL} -pi -e 's!<STDIN>!"n"!' ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e 's|_PERL_|${PERL}|' ${WRKSRC}/grepmail

.include <bsd.port.mk>
