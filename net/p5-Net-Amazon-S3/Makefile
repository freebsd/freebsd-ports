# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-S3
PORTVERSION=	0.58
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use the Amazon S3 - Simple Storage Service

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Data-Stream-Bulk>=0.06:${PORTSDIR}/devel/p5-Data-Stream-Bulk \
		p5-DateTime-Format-HTTP>=0:${PORTSDIR}/devel/p5-DateTime-Format-HTTP \
		p5-DateTime-Format-ISO8601>=0:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Digest-MD5-File>=0:${PORTSDIR}/security/p5-Digest-MD5-File \
		p5-LWP-UserAgent-Determined>=0:${PORTSDIR}/www/p5-LWP-UserAgent-Determined \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0.16:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types-DateTime-MoreCoercions>=0.07:${PORTSDIR}/devel/p5-MooseX-Types-DateTime-MoreCoercions \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon::S3.3 Net::Amazon::S3::Bucket.3 \
		Net::Amazon::S3::Request::GetObjectAccessControl.3 \
		Net::Amazon::S3::Client.3 \
		Net::Amazon::S3::Client::Bucket.3 \
		Net::Amazon::S3::Request::CompleteMultipartUpload.3 \
		Net::Amazon::S3::Request::DeleteMultiObject.3 \
		Net::Amazon::S3::Request::InitiateMultipartUpload.3 \
		Net::Amazon::S3::Request::ListAllMyBuckets.3 \
		Net::Amazon::S3::Request::ListParts.3 \
		Net::Amazon::S3::Request::PutObject.3 \
		Net::Amazon::S3::Request::PutPart.3 \
		Net::Amazon::S3::HTTPRequest.3 \
		Net::Amazon::S3::Request::ListBucket.3 \
		Net::Amazon::S3::Request::DeleteObject.3 \
		Net::Amazon::S3::Request::DeleteBucket.3 \
		Net::Amazon::S3::Client::Object.3 \
		Net::Amazon::S3::Request::GetBucketLocationConstraint.3 \
		Net::Amazon::S3::Request::SetBucketAccessControl.3 \
		Net::Amazon::S3::Request::SetObjectAccessControl.3 \
		Net::Amazon::S3::Request::GetBucketAccessControl.3 \
		Net::Amazon::S3::Request::GetObject.3 \
		Net::Amazon::S3::Request.3 \
		Net::Amazon::S3::Request::CreateBucket.3

MAN1=		s3cl.1

.include <bsd.port.mk>
