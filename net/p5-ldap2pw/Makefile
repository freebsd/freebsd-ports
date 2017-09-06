# $FreeBSD$

PORTNAME=	ldap2pw
PORTVERSION=	20170906
CATEGORIES=	net
MASTER_SITES=	GH
PKGNAMEPREFIX=  p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Synchronize local user database with LDAP directory

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-perl-ldap>=0:net/p5-perl-ldap
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure run

USE_GITHUB=	yes
GH_ACCOUNT=	dag-erling

PLIST_FILES=	bin/${PORTNAME} ${SITE_MAN1_REL}/${PORTNAME}.1.gz

.include <bsd.port.mk>
