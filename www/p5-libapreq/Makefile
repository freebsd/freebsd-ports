# New ports collection makefile for:	p5-libapreq
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	libapreq
PORTVERSION=	1.34
CATEGORIES=	www perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic Apache Request Library

.if defined(WITH_MODPERL2)
IGNORE=		this port does not support mod_perl2
.else
RUN_DEPENDS?=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test
.endif

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

PERL_CONFIGURE=	yes
USE_APACHE=	13

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} > 13
IGNORE=	build only with apache13
.endif

MAN3=		Apache::Cookie.3 Apache::Request.3 Apache::libapreq.3 \
		libapreq.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/c/testapreq
	@${MKDIR} ${EXAMPLESDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/eg/c/testapreq/* ${EXAMPLESDIR}/c/testapreq
	${INSTALL_SCRIPT} ${WRKSRC}/eg/perl/* ${EXAMPLESDIR}/perl
.endif

.include <bsd.port.post.mk>
