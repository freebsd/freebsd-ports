# New ports collection makefile for:   p5-Authen-NTLM
# Date created:                        June 07 2006
# Whom:                                James Thomason <james@divide.org>
#
#
# $FreeBSD$

PORTNAME=	NTLM
PORTVERSION=	1.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	james@divide.org
COMMENT=	Perl extension to authenticate against an NTLM server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Authen::NTLM.3

.include <bsd.port.mk>
