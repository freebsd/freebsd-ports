# New ports collection makefile for:	Net-Google
# Date created:	   04 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-Google
PORTVERSION=	0.52
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Google.3 Net::Google::Cache.3 Net::Google::Response.3 \
		Net::Google::Search.3 Net::Google::Spelling.3 \
		Net::Google::Service.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

SITE_PERL?=     ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

PERL_MAJOR=${PERL_VER:C|^([1-9]+).*|\1|}
PERL_MINOR=${PERL_VER:C|^[1-9]+\.0*([1-9]+).*|\1|}

.if ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 6
BUILD_DEPENDS+= ${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif # ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 6

.include <bsd.port.post.mk>
