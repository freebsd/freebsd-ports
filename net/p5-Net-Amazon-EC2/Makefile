# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-EC2
PORTVERSION=	0.23
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl interface to the Amazon Elastic Compute Cloud

RUN_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Digest-HMAC>=1.01:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Moose>=0.38:${PORTSDIR}/devel/p5-Moose \
		p5-XML-Simple>=2.18:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon::EC2.3 \
		Net::Amazon::EC2::Attachment.3 \
		Net::Amazon::EC2::AvailabilityZone.3 \
		Net::Amazon::EC2::AvailabilityZoneMessage.3 \
		Net::Amazon::EC2::BlockDeviceMapping.3 \
		Net::Amazon::EC2::BundleInstanceResponse.3 \
		Net::Amazon::EC2::ConfirmProductInstanceResponse.3 \
		Net::Amazon::EC2::ConsoleOutput.3 \
		Net::Amazon::EC2::CreateVolumePermission.3 \
		Net::Amazon::EC2::DescribeAddress.3 \
		Net::Amazon::EC2::DescribeImageAttribute.3 \
		Net::Amazon::EC2::DescribeImagesResponse.3 \
		Net::Amazon::EC2::DescribeInstanceAttributeResponse.3 \
		Net::Amazon::EC2::DescribeKeyPairsResponse.3 \
		Net::Amazon::EC2::DescribeTags.3 \
		Net::Amazon::EC2::EbsBlockDevice.3 \
		Net::Amazon::EC2::EbsInstanceBlockDeviceMapping.3 \
		Net::Amazon::EC2::Error.3 \
		Net::Amazon::EC2::Errors.3 \
		Net::Amazon::EC2::GroupSet.3 \
		Net::Amazon::EC2::InstanceBlockDeviceMapping.3 \
		Net::Amazon::EC2::InstancePassword.3 \
		Net::Amazon::EC2::InstanceState.3 \
		Net::Amazon::EC2::InstanceStateChange.3 \
		Net::Amazon::EC2::IpPermission.3 \
		Net::Amazon::EC2::IpRange.3 \
		Net::Amazon::EC2::KeyPair.3 \
		Net::Amazon::EC2::LaunchPermission.3 \
		Net::Amazon::EC2::LaunchPermissionOperation.3 \
		Net::Amazon::EC2::MonitoredInstance.3 \
		Net::Amazon::EC2::PlacementResponse.3 \
		Net::Amazon::EC2::ProductCode.3 \
		Net::Amazon::EC2::ProductInstanceResponse.3 \
		Net::Amazon::EC2::Region.3 \
		Net::Amazon::EC2::ReservationInfo.3 \
		Net::Amazon::EC2::ReservedInstance.3 \
		Net::Amazon::EC2::ReservedInstanceOffering.3 \
		Net::Amazon::EC2::RunningInstances.3 \
		Net::Amazon::EC2::SecurityGroup.3 \
		Net::Amazon::EC2::Snapshot.3 \
		Net::Amazon::EC2::SnapshotAttribute.3 \
		Net::Amazon::EC2::StateReason.3 \
		Net::Amazon::EC2::TagSet.3 \
		Net::Amazon::EC2::UserData.3 \
		Net::Amazon::EC2::UserIdGroupPair.3 \
		Net::Amazon::EC2::Volume.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
