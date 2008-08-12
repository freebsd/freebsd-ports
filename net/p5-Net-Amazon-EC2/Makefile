# New ports collection makefile for:	p5-Net-Amazon-EC2
# Date created:		2007-10-30
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon-EC2
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl interface to the Amazon Elastic Compute Cloud

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Digest-HMAC>=1.01:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		p5-XML-Simple>=2.18:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Moose>=0.38:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon::EC2.3 \
		Net::Amazon::EC2::AvailabilityZone.3 \
		Net::Amazon::EC2::BlockDeviceMapping.3 \
		Net::Amazon::EC2::ConfirmProductInstanceResponse.3 \
		Net::Amazon::EC2::ConsoleOutput.3 \
		Net::Amazon::EC2::DescribeAddress.3 \
		Net::Amazon::EC2::DescribeImageAttribute.3 \
		Net::Amazon::EC2::DescribeImagesResponse.3 \
		Net::Amazon::EC2::DescribeKeyPairsResponse.3 \
		Net::Amazon::EC2::Error.3 \
		Net::Amazon::EC2::Errors.3 \
		Net::Amazon::EC2::GroupSet.3 \
		Net::Amazon::EC2::InstanceState.3 \
		Net::Amazon::EC2::IpPermission.3 \
		Net::Amazon::EC2::IpRange.3 \
		Net::Amazon::EC2::KeyPair.3 \
		Net::Amazon::EC2::LaunchPermission.3 \
		Net::Amazon::EC2::LaunchPermissionOperation.3 \
		Net::Amazon::EC2::PlacementResponse.3 \
		Net::Amazon::EC2::ProductCode.3 \
		Net::Amazon::EC2::ProductInstanceResponse.3 \
		Net::Amazon::EC2::ReservationInfo.3 \
		Net::Amazon::EC2::RunningInstances.3 \
		Net::Amazon::EC2::SecurityGroup.3 \
		Net::Amazon::EC2::TerminateInstancesResponse.3 \
		Net::Amazon::EC2::UserData.3 \
		Net::Amazon::EC2::UserIdGroupPair.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
