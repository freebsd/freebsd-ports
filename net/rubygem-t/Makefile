# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line power tool for Twitter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-geokit>=1.8.3:${PORTSDIR}/graphics/rubygem-geokit \
		rubygem-htmlentities>=4.3:${PORTSDIR}/textproc/rubygem-htmlentities \
		rubygem-launchy>=2.4:${PORTSDIR}/devel/rubygem-launchy \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-retryable>=1.3:${PORTSDIR}/devel/rubygem-retryable \
		rubygem-thor>=0.19.1:${PORTSDIR}/devel/rubygem-thor \
		rubygem-twitter>=5.12:${PORTSDIR}/net/rubygem-twitter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/t

post-patch:
# adjust gemspec for "retryable ~> 1.3"
	@${REINPLACE_CMD} -e '79 s|"~>"|">="|' ${WRKSRC}/${GEM_NAME}.gemspec

.include <bsd.port.mk>
