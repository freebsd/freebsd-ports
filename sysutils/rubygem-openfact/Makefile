PORTNAME=	openfact
PORTVERSION=	5.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
WWW=		https://github.com/OpenVoxProject/openfact/

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-base64>0.1:converters/rubygem-base64 \
		rubygem-hocon>=1.3<2:devel/rubygem-hocon \
		rubygem-logger>=1.7:devel/rubygem-logger \
		rubygem-thor>=1.0.1<2.0:devel/rubygem-thor
# Soft dependencies that resolve more FreeBSD facts
RUN_DEPENDS+=	rubygem-ruby-augeas>0:textproc/rubygem-ruby-augeas \
		rubygem-ffi>=1.0:devel/rubygem-ffi \
		rubygem-rexml>0:textproc/rubygem-rexml \
		rubygem-sys-filesystem>0:sysutils/rubygem-sys-filesystem

USES=		cpe gem

CONFLICTS_INSTALL=	facter rubygem-facter # bin/facter

NO_ARCH=	yes

PLIST_FILES=	bin/facter

.include <bsd.port.mk>
