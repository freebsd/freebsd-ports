# New ports collection makefile for:	Apache-AuthTicket
# Date created:				Sun Dec 31 19:57:53 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.40
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules that implement a cookie-based authentication system

RUN_DEPENDS=	${SITE_PERL}/Apache/AuthCookie.pm:${PORTSDIR}/www/p5-Apache-AuthCookie \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthTicket.3 Apache2::AuthTicket.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
