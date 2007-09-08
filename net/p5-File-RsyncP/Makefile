# New ports collection makefile for:	p5-File-RsyncP
# Date created:				Mon Dec 22 10:30:25 GMT 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	File-RsyncP
PORTVERSION=	0.68
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl Rsync client

RUN_DEPENDS=	p5-Getopt-Long>=2.24:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.7.3+

MAN3=		File::RsyncP.3 \
		File::RsyncP::Digest.3 \
		File::RsyncP::FileIO.3 \
		File::RsyncP::FileList.3

.include <bsd.port.mk>
