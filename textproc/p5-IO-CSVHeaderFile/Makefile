# New ports collection makefile for:	p5-IO-CSVHeaderFile
# Date created:				Nov 23 03:11:08 MSK 2004
# Whom:					Vasek Balcar <vasek@ti.cz>
#
# $FreeBSD$
#

PORTNAME=	IO-CSVHeaderFile
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	vasek@ti.cz
COMMENT=	Perl module to automate reads from CSV formatted text files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::CSVHeaderFile.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Needs perl 5.6.0 or higher, install lang/perl5.6 and try again"
.endif

.include <bsd.port.post.mk>
