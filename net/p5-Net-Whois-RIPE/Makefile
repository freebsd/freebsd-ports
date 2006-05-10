# ex:ts=8
# Ports collection makefile for:	p5-Net-Whois-RIPE
# Date created:			Sep 11, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-RIPE
PORTVERSION=	1.23
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/P/PA/PAULG
PKGNAMEPREFIX=	p5-

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Implementation of RIPE Whois

PERL_MODBUILD=	yes

MAN3=	Net::Whois::RIPE::Iterator.3 \
	Net::Whois::RIPE::Object.3 \
	Net::Whois::RIPE.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
post-patch:
	${REINPLACE_CMD} -e '/warnings/d' ${WRKSRC}/Build.PL
post-configure:
	${PERL} -pi -e 's/-I\S+PERL\S+ //g if m{PERL_DL_NONLAZY}' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
