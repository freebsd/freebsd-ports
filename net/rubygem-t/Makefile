# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t
PORTVERSION=	2.9.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line power tool for Twitter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-geokit>=1.8.3:${PORTSDIR}/graphics/rubygem-geokit \
		rubygem-htmlentities>=4.3:${PORTSDIR}/textproc/rubygem-htmlentities \
		rubygem-launchy>=2.4:${PORTSDIR}/devel/rubygem-launchy \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-retryable>=2.0:${PORTSDIR}/devel/rubygem-retryable \
		rubygem-thor>=0.19.1:${PORTSDIR}/devel/rubygem-thor \
		rubygem-twitter>=5.13:${PORTSDIR}/net/rubygem-twitter

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/t

.include <bsd.port.mk>
