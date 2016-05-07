# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-Htpasswd
PORTVERSION=	0.171
PORTREVISION=	1
CATEGORIES=	security perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Authen::Htpasswd - interface to read and modify Apache .htpasswd files
TAGS=		apache authentication pass password md5 sha1 crypto

COMMON_DEPENDS=	p5-IO-LockedFile>=0:devel/p5-IO-LockedFile \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
