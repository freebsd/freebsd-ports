# New ports collection makefile for:	p5-OurNet-BBS
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	OurNet-BBS
PORTVERSION=	1.66
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Component Object Model for BBS systems

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${SITE_PERL}/${PERL_ARCH}/Crypt/GOST.pm:${PORTSDIR}/security/p5-Crypt-GOST \
		${SITE_PERL}/${PERL_ARCH}/Crypt/IDEA.pm:${PORTSDIR}/security/p5-Crypt-IDEA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael \
		${SITE_PERL}/${PERL_ARCH}/Crypt/TEA.pm:${PORTSDIR}/security/p5-Crypt-TEA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Twofish.pm:${PORTSDIR}/security/p5-Crypt-Twofish \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Twofish2.pm:${PORTSDIR}/security/p5-Crypt-Twofish2 \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Crypt/Blowfish_PP.pm:${PORTSDIR}/security/p5-Crypt-Blowfish_PP \
		${SITE_PERL}/Crypt/DES_PP.pm:${PORTSDIR}/security/p5-Crypt-DES_PP \
		${SITE_PERL}/Crypt/Rijndael_PP.pm:${PORTSDIR}/security/p5-Crypt-Rijndael_PP \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/GnuPG/Interface.pm:${PORTSDIR}/security/p5-GnuPG-Interface \
		${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Mail/Box.pm:${PORTSDIR}/mail/p5-Mail-Box \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Net/Daemon.pm:${PORTSDIR}/net/p5-Net-Daemon \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/OurNet/BBSAgent.pm:${PORTSDIR}/net/p5-OurNet-BBSAgent \
		${SITE_PERL}/RPC/PlServer.pm:${PORTSDIR}/net/p5-PlRPC \
		${SITE_PERL}/enum.pm:${PORTSDIR}/devel/p5-enum
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.7.3+

MAN1=		bbsboard.1 bbscomd.1 bbsmail.1
MAN3=		OurNet::BBS.3 OurNet::BBS::Roadmap.3 OurNet::BBS::Tutorial.3

.include <bsd.port.mk>
