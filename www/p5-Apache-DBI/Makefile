# Created by: Igor Vinokurov <igor@zynaps.ru>
# $FreeBSD$

PORTNAME=	Apache-DBI
PORTVERSION=	1.12
CATEGORIES=	www databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI persistent connection, authentication and authorization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-Apache-DBI-mp[12]*

USES=		perl5
USE_PERL5=	configure
USE_APACHE?=	22+

MAN3=		Apache::DBI.3 Apache::AuthDBI.3
PLIST_FILES=	%%SITE_PERL%%/Apache/DBI.pm \
		%%SITE_PERL%%/Apache/AuthDBI.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache/DBI
PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Apache \
		%%SITE_PERL%%/Apache

.include <bsd.port.mk>
