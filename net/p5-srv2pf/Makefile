# $FreeBSD$

PORTNAME=	srv2pf
PORTVERSION=	20151106
CATEGORIES=	net
MASTER_SITES=	GH
PKGNAMEPREFIX=  p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Create and update PF tables from LDAP groups

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-perl-ldap>=0:net/p5-perl-ldap
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	dag-erling

USES=		perl5
USE_PERL5=	configure run

PLIST_FILES=	bin/${PORTNAME} ${SITE_MAN1_REL}/${PORTNAME}.1.gz

.include <bsd.port.mk>
