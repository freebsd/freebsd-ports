# New ports collection makefile for:	p5-File-CounterFile
# Date created:				Jan 28 2000
# Whom:					Wei-chun Chao
#
# $FreeBSD$
#

PORTNAME=	File-CounterFile
PORTVERSION=	1.03
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Perl module for persistent counter class

PERL_CONFIGURE=	yes

MAN3=		File::CounterFile.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-configure:
	cd ${WRKSRC}; \
	${PERL} -pi -e 's|(.*Fcntl.*) SEEK_SET(.*)|\1\2\nuse POSIX qw(SEEK_SET);|;' \
		CounterFile.pm
.endif

.include <bsd.port.post.mk>
