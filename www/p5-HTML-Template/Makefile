# New ports collection makefile for:	p5-HTML-Template
# Date Created:				26 Oct, 2000
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template
PORTVERSION=	2.6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org

.include <bsd.port.pre.mk>

.if !exists(${PREFIX}/lib/perl5/5.6.1/File/Spec.pm)
BUILD_DEPENDS=	${PERL_INC}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS=	${PERL_INC}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

PERL_CONFIGURE=	yes

MAN3=		HTML::Template.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
PERL_INC=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

post-patch:
	${PERL} -i -pe 's@%%PERL_INC%%@${PERL_INC}@' ${WRKSRC}/Template.pm

.include <bsd.port.post.mk>
