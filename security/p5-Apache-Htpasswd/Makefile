# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Apache-Htpasswd
PORTVERSION=	1.8
CATEGORIES=	security perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Manage Unix crypt-style password file

BUILD_DEPENDS=	p5-Crypt-PasswdMD5>=0:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Digest-SHA1>=2.0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Apache::Htpasswd.3

.include <bsd.port.mk>
