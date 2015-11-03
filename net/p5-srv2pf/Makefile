# $FreeBSD$

PORTNAME=	srv2pf
PORTVERSION=	20151101
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	des@FreeBSD.org
COMMENT=	Create and update PF tables from LDAP groups

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	dag-erling

USES=		perl5
USE_PERL5=	configure run

PLIST_FILES=	bin/srv2pf

.include <bsd.port.mk>
