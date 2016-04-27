# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	backup
PORTVERSION=	4.2.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perform backup operations on remote and local environment

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-CFPropertyList>=2.3.1:devel/rubygem-CFPropertyList \
		rubygem-addressable>=2.3.5:www/rubygem-addressable \
		rubygem-atomic>=1.1.14:devel/rubygem-atomic \
		rubygem-aws-ses>=0.5.0:net/rubygem-aws-ses \
		rubygem-buftok>=0.2.0:devel/rubygem-buftok \
		rubygem-builder32>=3.2.2:devel/rubygem-builder32 \
		rubygem-descendants_tracker>=0.0.3:devel/rubygem-descendants_tracker \
		rubygem-dogapi>=1.11.0:net/rubygem-dogapi \
		rubygem-dropbox-sdk>=1.5.1:net/rubygem-dropbox-sdk \
		rubygem-equalizer>=0.0.9:devel/rubygem-equalizer \
		rubygem-excon>=0.44.4:devel/rubygem-excon \
		rubygem-faraday>=0.8.8:www/rubygem-faraday \
		rubygem-fission>=0.5.0:emulators/rubygem-fission \
		rubygem-flowdock>=0.4.0:www/rubygem-flowdock \
		rubygem-fog>=1.28.0:devel/rubygem-fog \
		rubygem-fog-atmos>=0.1.0:net/rubygem-fog-atmos \
		rubygem-fog-aws>=0.1.1:net/rubygem-fog-aws \
		rubygem-fog-brightbox>=0.7.1:net/rubygem-fog-brightbox \
		rubygem-fog-core>=1.29.0:devel/rubygem-fog-core \
		rubygem-fog-ecloud>=0.0.2:net/rubygem-fog-ecloud \
		rubygem-fog-json>=1.0.0:devel/rubygem-fog-json \
		rubygem-fog-profitbricks>=0.0.2:net/rubygem-fog-profitbricks \
		rubygem-fog-radosgw>=0.0.3:net/rubygem-fog-radosgw \
		rubygem-fog-riakcs>=0.1.0:net/rubygem-fog-riakcs \
		rubygem-fog-sakuracloud>=1.0.0:net/rubygem-fog-sakuracloud \
		rubygem-fog-serverlove>=0.1.1:net/rubygem-fog-serverlove \
		rubygem-fog-softlayer>=0.4.1:net/rubygem-fog-softlayer \
		rubygem-fog-storm_on_demand>=0.1.0:net/rubygem-fog-storm_on_demand \
		rubygem-fog-terremark>=0.0.4:net/rubygem-fog-terremark \
		rubygem-fog-vmfusion>=0.0.1:net/rubygem-fog-vmfusion \
		rubygem-fog-voxel>=0.0.2:net/rubygem-fog-voxel \
		rubygem-fog-xml>=0.1.1:textproc/rubygem-fog-xml \
		rubygem-formatador>=0.2.5:devel/rubygem-formatador \
		rubygem-hipchat>=1.0.1:net-im/rubygem-hipchat \
		rubygem-http>=0.5.0:www/rubygem-http \
		rubygem-http_parser.rb>=0.6.0:net/rubygem-http_parser.rb \
		rubygem-httparty>=0.12.0:www/rubygem-httparty \
		rubygem-inflecto>=0.0.2:devel/rubygem-inflecto \
		rubygem-ipaddress>=0.8.0:net/rubygem-ipaddress \
		rubygem-json>=1.8.2:devel/rubygem-json \
		rubygem-mail25>=2.5.4:mail/rubygem-mail25 \
		rubygem-memoizable>=0.4.0:devel/rubygem-memoizable \
		rubygem-mime-types1>=1.25.1:misc/rubygem-mime-types1 \
		rubygem-multi_json>=1.10.1:devel/rubygem-multi_json \
		rubygem-multi_xml>=0.5.5:textproc/rubygem-multi_xml \
		rubygem-multipart-post>=1.2.0:www/rubygem-multipart-post \
		rubygem-net-scp>=1.2.1:security/rubygem-net-scp \
		rubygem-net-sftp>=2.1.2:security/rubygem-net-sftp \
		rubygem-net-ssh>=2.9.2:security/rubygem-net-ssh \
		rubygem-nokogiri>=1.6.6.2:textproc/rubygem-nokogiri \
		rubygem-open4>=1.3.0:devel/rubygem-open4 \
		rubygem-pagerduty>=2.0.0:www/rubygem-pagerduty \
		rubygem-polyglot>=0.3.3:devel/rubygem-polyglot \
		rubygem-simple_oauth>=0.2.0:net/rubygem-simple_oauth \
		rubygem-thor>=0.18.1:devel/rubygem-thor \
		rubygem-thread_safe1>=0.1.3:devel/rubygem-thread_safe1 \
		rubygem-treetop>=1.4.15:devel/rubygem-treetop \
		rubygem-twitter>=5.5.0:net/rubygem-twitter \
		rubygem-unf>=0.1.3:textproc/rubygem-unf \
		rubygem-unf_ext>=0.0.6:textproc/rubygem-unf_ext \
		rubygem-xml-simple>=1.1.4:textproc/rubygem-xml-simple

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/backup

.include <bsd.port.mk>
