# New ports collection makefile for:	p5-Crypt-PasswdMD5
# Date created:				18 June, 2002
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-PasswdMD5
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides interoperable MD5-based crypt() function

PERL_CONFIGURE=	yes

MAN3=		Crypt::PasswdMD5.3

pre-patch:
	@${REINPLACE_CMD} -e 's|[[:cntrl:]]$$||g' ${WRKSRC}/PasswdMD5.pm

.include <bsd.port.mk>
