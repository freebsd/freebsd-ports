# New ports collection makefile for:	p5-CGI-Ex
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Ex
PORTVERSION=	2.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CGI utility suite - makes powerful application writing fun and easy

RUN_DEPENDS=	${SITE_PERL}/Template/Alloy.pm:${PORTSDIR}/www/p5-Template-Alloy
BUILD_DEPENDS=	${RUN_DEPENDS}

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
