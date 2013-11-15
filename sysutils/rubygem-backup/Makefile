# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	backup
PORTVERSION=	3.9.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perform backup operations on remote and local environment

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder32>=3.2.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-dropbox-sdk>=1.5.1:${PORTSDIR}/net/rubygem-dropbox-sdk \
		rubygem-excon>=0.25.3:${PORTSDIR}/devel/rubygem-excon \
		rubygem-faraday>=0.8.7:${PORTSDIR}/www/rubygem-faraday \
		rubygem-fog>=1.13.0:${PORTSDIR}/devel/rubygem-fog \
		rubygem-formatador>=0.2.4:${PORTSDIR}/devel/rubygem-formatador \
		rubygem-hipchat>=0.11.0:${PORTSDIR}/net-im/rubygem-hipchat \
		rubygem-httparty>=0.11.0:${PORTSDIR}/www/rubygem-httparty \
		rubygem-json>=1.8.0:${PORTSDIR}/devel/rubygem-json \
		rubygem-mail>=2.5.4:${PORTSDIR}/mail/rubygem-mail \
		rubygem-mime-types>=1.23:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-multi_json>=1.7.7:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-multi_xml>=0.5.4:${PORTSDIR}/textproc/rubygem-multi_xml \
		rubygem-multipart-post>=1.2.0:${PORTSDIR}/www/rubygem-multipart-post \
		rubygem-net-scp>=1.1.2:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-sftp>=2.1.2:${PORTSDIR}/security/rubygem-net-sftp \
		rubygem-net-ssh>=2.6.8:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-nokogiri>=1.5.10:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-open4>=1.3.0:${PORTSDIR}/devel/rubygem-open4 \
		rubygem-polyglot>=0.3.3:${PORTSDIR}/devel/rubygem-polyglot \
		rubygem-ruby-hmac>=0.4.0:${PORTSDIR}/security/rubygem-ruby-hmac \
		rubygem-simple_oauth>=0.2.0:${PORTSDIR}/net/rubygem-simple_oauth \
		rubygem-thor>=0.18.1:${PORTSDIR}/devel/rubygem-thor \
		rubygem-treetop>=1.4.14:${PORTSDIR}/devel/rubygem-treetop \
		rubygem-twitter>=4.8.1:${PORTSDIR}/net/rubygem-twitter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/backup

.include <bsd.port.mk>
