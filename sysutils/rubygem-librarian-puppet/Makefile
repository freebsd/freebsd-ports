# $FreeBSD$

PORTNAME=	librarian-puppet
PORTVERSION=	2.2.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Tool for management and bundling Puppet modules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PKGNAMEPREFIX}librarianp>=0.6.3:${PORTSDIR}/devel/rubygem-librarianp \
		${PKGNAMEPREFIX}puppet_forge>=1.0:${PORTSDIR}/sysutils/rubygem-puppet_forge \
		${PKGNAMEPREFIX}rsync>0:${PORTSDIR}/net/rubygem-rsync

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/librarian-puppet

.include <bsd.port.mk>
