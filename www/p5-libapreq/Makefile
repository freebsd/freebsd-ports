# New ports collection makefile for:	p5-libapreq
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	libapreq
PORTVERSION=	1.33
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic Apache Request Library

.if defined(WITH_MODPERL2)
IGNORE=		This port does not support mod_perl2
.else
RUN_DEPENDS?=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::Cookie.3 Apache::Request.3 Apache::libapreq.3 \
		libapreq.3

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi~ -e '$$_="" if ($$.>37 && $$.<63) || /PREREQ_PM/' \
		${WRKSRC}/Makefile.PL
.if ${PERL_LEVEL} < 500600
	@${PERL} -pi~ -e '$$_="#define aTHX_\n" if $$. == 155' \
		${WRKSRC}/c/apache_request.h
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/c/testapreq
	@${MKDIR} ${EXAMPLESDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/eg/c/testapreq/* ${EXAMPLESDIR}/c/testapreq
	${INSTALL_SCRIPT} ${WRKSRC}/eg/perl/* ${EXAMPLESDIR}/perl
.endif

.include <bsd.port.post.mk>
