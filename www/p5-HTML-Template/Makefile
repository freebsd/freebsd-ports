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

PERL_CONFIGURE=	yes

MAN3=		HTML::Template.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -i -pe 's@%%PERL_INC%%@${SITE_PERL}@' ${WRKSRC}/Template.pm

.include <bsd.port.mk>

# ${PERL} defined after bsd.port.post.mk.  So place this after .include line.
USE_FILESPEC!=	${PERL} -MFile::Spec -e 'print $$File::Spec::VERSION<0.82'
.if (${USE_FILESPEC} == 1)
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif
