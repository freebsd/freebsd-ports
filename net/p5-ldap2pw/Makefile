# $FreeBSD$

PORTNAME=	ldap2pw
PORTVERSION=	20151101
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	des@FreeBSD.org
COMMENT=	Synchronize local user database with LDAP directory

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

USE_GITHUB=	yes
GH_ACCOUNT=	dag-erling

USES=		perl5
USE_PERL5=	configure run

PLIST_FILES=	bin/ldap2pw

.include <bsd.port.mk>
