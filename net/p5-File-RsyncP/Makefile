# New ports collection makefile for:	p5-File-RsyncP
# Date created:				Mon Dec 22 10:30:25 GMT 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	File-RsyncP
PORTVERSION=	0.44
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Perl Rsync client

PERL_CONFIGURE=	yes

MAN3=		File::RsyncP.3 \
		File::RsyncP::Digest.3 \
		File::RsyncP::FileList.3 \
		File::RsyncP::FileIO.3

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include <bsd.port.mk>
