# $FreeBSD$

PORTNAME=	net-ssh-krb
DISTVERSION=	0.5.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Add Kerberos authentication capabilities to Net::SSH

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gssapi>=1.3:security/rubygem-gssapi \
		rubygem-net-ssh>=2.0:security/rubygem-net-ssh

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
