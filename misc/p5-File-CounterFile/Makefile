# New ports collection makefile for:	p5-File-CounterFile
# Date created:				Jan 28 2000
# Whom:					Wei-chun Chao
#
# $FreeBSD$
#

PORTNAME=	File-CounterFile
PORTVERSION=	1.04
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Perl module for persistent counter class

PERL_CONFIGURE=	yes

MAN3=		File::CounterFile.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
# make PREFIX-clean under perl 5.005_03
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
