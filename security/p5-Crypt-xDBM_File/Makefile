# New ports collection makefile for:	Crypt-xDBM_File
# Date created:				Tue Dec 30 08:56:41 CST 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Crypt-xDBM_File
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module encrypt almost any kind of dbm file

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::xDBM_File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
