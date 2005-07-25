# New ports collection makefile for:	textproc/p5-Filter-Simple
# Date created:				15 October 2003
# Whom:					philip@p6m7g8.com
#
# $FreeBSD$
#

PORTNAME=	Filter-Simple
PORTVERSION=	0.82
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filter
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	Simplified source filtering

PERL_CONFIGURE=	yes

MAN3=	Filter::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS+=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -i -pe '$$_ = "" if /no warnings/' \
		${WRKSRC}/lib/Filter/Simple.pm
.endif
.endif

.include <bsd.port.post.mk>
