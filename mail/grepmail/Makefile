# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION=	4.50
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

PERL_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		grepmail.1

post-extract:
	# we don't want to build the FastReader module
	@${RM} -f ${WRKSRC}/FastReader/Makefile.PL

post-patch:
	@${PERL} -pi -e 's!<STDIN>!"n"!' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
