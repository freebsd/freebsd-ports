# Ports collection Makefile for:		p5-AxKit-XSP-ESQL
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-ESQL
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	adam@migus.org
COMMENT=	An Extended SQL taglib for AxKit eXtensible Server Pages

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit \
		${SITE_PERL}/AxKit/XSP/Util.pm:${PORTSDIR}/www/p5-AxKit-XSP-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		AxKit::XSP::ESQL.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
