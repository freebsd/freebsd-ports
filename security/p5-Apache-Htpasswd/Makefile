# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Apache-Htpasswd
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	security perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Manage Unix crypt-style password file

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-Digest-SHA1>=2.0:security/p5-Digest-SHA1

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
