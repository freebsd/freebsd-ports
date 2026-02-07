PORTNAME=	ruby_smb
PORTVERSION=	3.3.13
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Message creator and parser for the SMB protocol family
WWW=		https://github.com/rapid7/ruby_smb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-bindata24>=2.4.15<2.4.15_99:devel/rubygem-bindata24 \
		rubygem-openssl-ccm>=0:security/rubygem-openssl-ccm \
		rubygem-openssl-cmac>=0:security/rubygem-openssl-cmac \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-windows_error>=0:devel/rubygem-windows_error

USES=		gem shebangfix
SHEBANG_FILES=	examples/delete_file.rb \
		examples/net_share_enum_all.rb \
		examples/pipes.rb \
		examples/rename_file.rb

NO_ARCH=	yes

.include <bsd.port.mk>
