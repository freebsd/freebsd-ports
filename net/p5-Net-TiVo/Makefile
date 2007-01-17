# New ports collection makefile for:	Net-TiVo
# Date created:				Jan 10 2006
# Whom:					Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-TiVo
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	boumenot@gmail.com
COMMENT=	Framework for accessing TiVo using XML/HTTP

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::TiVo.3 \
		Net::TiVo::Show.3 \
		Net::TiVo::Folder.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=		requires perl 5.8.x or later. Install lang/perl58 then try again
.endif

.include <bsd.port.post.mk>
