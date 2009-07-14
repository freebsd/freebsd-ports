# New ports collection makefile for:	p5-Apache-Htpasswd
# Date created:				Jul 17, 2009
# Whom:					Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Htpasswd
PORTVERSION=	1.8
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	A Perl module for managing Unix crypt-style password file

BUILD_DEPENDS=	p5-Crypt-PasswdMD5>=0:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Digest-SHA1>=2:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::Htpasswd.3

.include <bsd.port.mk>
