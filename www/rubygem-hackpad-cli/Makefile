# $FreeBSD$

PORTNAME=	hackpad-cli
PORTVERSION=	0.1.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@mose.com
COMMENT=	CLI for some remote hackpad operations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-cliprompt>=0.1.2:${PORTSDIR}/devel/rubygem-cliprompt \
		rubygem-configstruct>=0.1.0:${PORTSDIR}/devel/rubygem-configstruct \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-paint>=1.0.0:${PORTSDIR}/devel/rubygem-paint \
		rubygem-reverse_markdown>=1.0.0:${PORTSDIR}/textproc/rubygem-reverse_markdown \
		rubygem-thor>=0:${PORTSDIR}/devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/hpcli

.include <bsd.port.mk>
