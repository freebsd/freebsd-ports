# New ports collection makefile for:	p5-Blog-Spam
# Date created:		2010-11-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Blog-Spam
PORTVERSION=	1.0.2
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SK/SKX
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Blog & Forum SPAM Detection

RUN_DEPENDS=	p5-Net-CIDR-Lite>=0:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML \
		p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=		blogspam.1
MAN3=		Blog::Spam::API.3 \
		Blog::Spam::Plugin::00blacklist.3 \
		Blog::Spam::Plugin::00whitelist.3 \
		Blog::Spam::Plugin::Sample.3 \
		Blog::Spam::Plugin::badip.3 \
		Blog::Spam::Plugin::bayesian.3 \
		Blog::Spam::Plugin::bogusip.3 \
		Blog::Spam::Plugin::drone.3 \
		Blog::Spam::Plugin::dropme.3 \
		Blog::Spam::Plugin::emailtests.3 \
		Blog::Spam::Plugin::hashcash.3 \
		Blog::Spam::Plugin::httpbl.3 \
		Blog::Spam::Plugin::logger.3 \
		Blog::Spam::Plugin::lotsaurls.3 \
		Blog::Spam::Plugin::multilinks.3 \
		Blog::Spam::Plugin::rdns.3 \
		Blog::Spam::Plugin::requiremx.3 \
		Blog::Spam::Plugin::sfs.3 \
		Blog::Spam::Plugin::size.3 \
		Blog::Spam::Plugin::stopwords.3 \
		Blog::Spam::Plugin::strong.3 \
		Blog::Spam::Plugin::surbl.3 \
		Blog::Spam::Plugin::wordcount.3 \
		Blog::Spam::Server.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
RUN_DEPENDS+=	p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
