# New ports collection makefile for:	p5-XML-RPC
# Date created:				6 Sep 2001
# Whom:					Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	RPC-XML
PORTVERSION=	0.27
CATEGORIES=	net www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_GMAKE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::RPC::Server.3 \
		RPC::XML.3 \
		RPC::XML::Client.3 \
		RPC::XML::Parser.3

.include <bsd.port.pre.mk>
perl_major=	${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=	00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=	${_perl_minor:C|^.*(...)|\1|}
.if ${perl_minor} >= 100
perl_minor=	${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=	${PERL_VERSION:C|^.*(..)|\1|}
.else # ${perl_minor} < 100
_perl_patch=	0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=	${_perl_patch:C|^.*(..)|\1|}
.endif # ${perl_minor} < 100
PERL_LEVEL=	${perl_major}${perl_minor}${perl_patch}

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif # ${PERL_LEVEL} < 500601

.include <bsd.port.post.mk>
