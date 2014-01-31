# Created by: Zahatski Aliaksandr <zag@cpan.org>
# $FreeBSD$

PORTNAME=	WebDAO
PORTVERSION=	2.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZAG
PKGNAMEPREFIX=	p5-

MAINTAINER=	zag@cpan.org
COMMENT=	Platform for easy creation of web applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0.37:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-HTTP>=0.37:${PORTSDIR}/devel/p5-DateTime-Format-HTTP \
		p5-FCGI>=0.67:${PORTSDIR}/www/p5-FCGI \
		p5-HTTP-Body>=1.11:${PORTSDIR}/www/p5-HTTP-Body \
		p5-URI>=1.36:${PORTSDIR}/net/p5-URI \
		p5-XML-Flow>=0.86:${PORTSDIR}/textproc/p5-XML-Flow
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class

USES=		perl5
USE_PERL5=	configure

# maintainer section:
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
