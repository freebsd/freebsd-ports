# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	App-Regather
PORTVERSION=	0.81.02
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Script to perform actions on LDAP syncrepl events

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Config-Parser>=1.04:devel/p5-Config-Parser \
		p5-Config-Parser-ldap>=1.00:devel/p5-Config-Parser-ldap \
		p5-Data-Printer>=0.38:devel/p5-Data-Printer \
		p5-Mail-Tools>=0.80:mail/p5-Mail-Tools \
		p5-Net-DNS>=1.15:dns/p5-Net-DNS \
		p5-Template-Toolkit>=2.29:www/p5-Template-Toolkit \
		p5-perl-ldap>=0.65:net/p5-perl-ldap

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
