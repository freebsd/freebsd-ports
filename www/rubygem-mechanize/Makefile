# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mechanize
PORTVERSION=	2.7.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	WWW::Mechanize, a handy web browsing ruby object

RUN_DEPENDS=	rubygem-domain_name>=0.5.1:${PORTSDIR}/net/rubygem-domain_name \
		rubygem-http-cookie>=1.0.0:${PORTSDIR}/www/rubygem-http-cookie \
		rubygem-mime-types>=1.17.2:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-net-http-digest_auth>=1.1.1:${PORTSDIR}/www/rubygem-net-http-digest_auth \
		rubygem-net-http-persistent>=2.5.2:${PORTSDIR}/www/rubygem-net-http-persistent \
		rubygem-nokogiri>=1.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-ntlm-http>=0.1.1:${PORTSDIR}/www/rubygem-ntlm-http \
		rubygem-webrobots>=0.0.9:${PORTSDIR}/www/rubygem-webrobots

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
