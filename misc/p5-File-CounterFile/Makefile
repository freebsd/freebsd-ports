# New ports collection makefile for:	p5-File-CounterFile
# Date created:				Jan 28 2000
# Whom:					Wei-chun Chao
#
# $FreeBSD$
#

PORTNAME=	File-CounterFile
PORTVERSION=	0.12
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	wchao@isi.edu

USE_PERL5=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		File::CounterFile.3

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
