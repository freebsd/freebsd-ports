# $FreeBSD$

PORTNAME=	roadie
PORTVERSION=	3.1.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helper for generating HTML mails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-css_parser>=1.3.4:${PORTSDIR}/textproc/rubygem-css_parser \
		rubygem-nokogiri>=1.5.0:${PORTSDIR}/textproc/rubygem-nokogiri

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
