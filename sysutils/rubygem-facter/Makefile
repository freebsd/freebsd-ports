# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	facter
PORTVERSION=	4.0.44
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-hocon>=1.3:devel/rubygem-hocon \
		rubygem-thor>=1.0.1:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/facter ${GEMS_DIR}/facter

.include <bsd.port.pre.mk>

post-install:
	${RLN} ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter-${PORTVERSION} ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter

.include <bsd.port.post.mk>
