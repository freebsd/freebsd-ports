# $FreeBSD$

PORTNAME=	ruby_smb
PORTVERSION=	1.0.5
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Message creator and parser for the SMB protocol family

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-bindata>=0:devel/rubygem-bindata \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-windows_error>=0:devel/rubygem-windows_error

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	examples/delete_file.rb \
		examples/net_share_enum_all.rb \
		examples/pipes.rb \
		examples/rename_file.rb

.include <bsd.port.mk>
