# New ports collection makefile for:	p5-Net
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Net
PORTVERSION=	1.19
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
DISTNAME=	libnet-${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl5 modules to access and use network protocols

RUN_DEPENDS=	${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	< /dev/null

MAN3=		Net::Cmd.3 \
		Net::Config.3 \
		Net::Domain.3 \
		Net::FTP.3 \
		Net::NNTP.3 \
		Net::Netrc.3 \
		Net::POP3.3 \
		Net::SMTP.3 \
		Net::Time.3 \
		Net::libnetFAQ.3

.include <bsd.port.mk>
