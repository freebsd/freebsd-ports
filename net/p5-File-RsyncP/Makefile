# New ports collection makefile for:	p5-File-RsyncP
# Date created:				Mon Dec 22 10:30:25 GMT 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	File-RsyncP
PORTVERSION=	0.62
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl Rsync client

BUILD_DEPENDS=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::RsyncP.3 \
		File::RsyncP::Digest.3 \
		File::RsyncP::FileList.3 \
		File::RsyncP::FileIO.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
# inherited from devel/p5-Encode
IGNORE=		requires Perl 5.7.3 or above. Please install lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
