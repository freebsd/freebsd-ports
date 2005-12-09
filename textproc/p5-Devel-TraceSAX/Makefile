# New ports collection makefile for:    devel/p5-Devel-TraceSAX
# Date created:                         Dec  9 2005
# Whom:                                 Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-TraceSAX
PORTVERSION=	0.021
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Trace SAX events

BUILD_DEPENDS=	p5-Devel-TraceCalls>=0.03:${PORTSDIR}/devel/p5-Devel-TraceCalls \
		p5-XML-SAX-Machines>=0:${PORTSDIR}/textproc/p5-XML-SAX-Machines
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::TraceSAX.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
