# New ports collection makefile for:	p5-VUser-Google-ProvisioningAPI
# Date created:		2011-04-28
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VUser-Google-ProvisioningAPI
PORTVERSION=	0.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSMITH/vuser
PKGNAMEPREFIX=	p5-

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Perl module that implements the Google Provisioning API

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

MAN3=	VUser::Google::ProvisioningAPI::V2_0::EmailListEntry.3 \
	VUser::Google::ProvisioningAPI::V2_0::NicknameEntry.3 \
	VUser::Google::ProvisioningAPI::V2_0.3 \
	VUser::Google::ProvisioningAPI::V1_0.3 \
	VUser::Google::ProvisioningAPI.3 \
	VUser::Google::ProvisioningAPI::V2_0::EmailListRecipientEntry.3 \
	VUser::Google::ProvisioningAPI::V2_0::UserEntry.3

.include <bsd.port.mk>
