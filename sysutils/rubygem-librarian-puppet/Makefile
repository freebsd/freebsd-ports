PORTNAME=	librarian-puppet
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Tool for management and bundling Puppet modules
WWW=		https://github.com/rodjek/librarian-puppet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-librarianp>=0.6.3:devel/rubygem-librarianp \
		rubygem-puppet_forge>=2.1:sysutils/rubygem-puppet_forge \
		rubygem-rsync>0:net/rubygem-rsync

NO_ARCH=	yes
USES=		gem
PLIST_FILES=	bin/librarian-puppet

.include <bsd.port.mk>
