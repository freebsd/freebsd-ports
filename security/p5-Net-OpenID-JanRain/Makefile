# New ports collection makefile for:	p5-Net-OpenID-JanRain
# Date created:				2006-12-19
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenID-JanRain
PORTVERSION=	1.1.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	OpenID JanRain and Consumer with JanRain API

BUILD_DEPENDS=	${SITE_PERL}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/LWPx/ParanoidAgent.pm:${PORTSDIR}/www/p5-LWPx-ParanoidAgent \
		${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt \
    		${SITE_PERL}/Net/Yadis.pm:${PORTSDIR}/net/p5-Net-Yadis \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=		Net::OpenID::JanRain::Consumer.3 \
		Net::OpenID::JanRain::Server.3 \
		Net::OpenID::JanRain::Stores::FileStore.3 \
		Net::OpenID::JanRain::Stores::MySQLStore.3 \
		Net::OpenID::JanRain::Stores::PostgreSQLStore.3 \
		Net::OpenID::JanRain::Stores::SQLStore.3 \
		Net::OpenID::JanRain::Stores::SQLiteStore.3

.include <bsd.port.mk>
