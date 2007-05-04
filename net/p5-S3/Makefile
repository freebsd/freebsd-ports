# New ports collection makefile for:	p5-S3
# Date created:		2007-04-30
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	S3
PORTVERSION=	20061002
CATEGORIES=	net perl5
MASTER_SITES=	http://developer.amazonwebservices.com/connect/servlet/KbServlet/download/133-102-760/
PKGNAMEPREFIX=	p5-
DISTNAME=	s3-example-perl-library

MAINTAINER=	gslin@gslin.org
COMMENT=	A library in Perl for working with the Amazon S3 REST interface

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC\
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/s3-example-libraries/perl

do-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/S3
	${INSTALL_DATA} ${WRKSRC}/S3/* ${PREFIX}/${SITE_PERL_REL}/S3
	${INSTALL_DATA} ${WRKSRC}/S3.pm ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/s3-*.pl ${PREFIX}/bin

.include <bsd.port.mk>
