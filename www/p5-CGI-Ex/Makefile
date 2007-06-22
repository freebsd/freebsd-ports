# New ports collection makefile for:	p5-CGI-Ex
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Ex
PORTVERSION=	2.15
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CGI utility suite - makes powerful application writing fun and easy

PERL_CONFIGURE=	yes

MAN3=		CGI::Ex.3 CGI::Ex::App.3 CGI::Ex::Auth.3 CGI::Ex::Conf.3 \
		CGI::Ex::Die.3 CGI::Ex::Dump.3 CGI::Ex::Fill.3 \
		CGI::Ex::JSONDump.3 CGI::Ex::Template.3 CGI::Ex::Validate.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for i in app benchmark devel
	${MKDIR} ${EXAMPLESDIR}/${i}
.endfor
	${CP} -R ${WRKSRC}/samples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
