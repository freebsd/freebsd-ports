# $FreeBSD$

PORTNAME=	hiera-eyaml
PORTVERSION=	2.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsd@rig.rain.com
COMMENT=	Backend for Hiera that provides encryption/decryption for properties

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-trollop>=2.0:devel/rubygem-trollop \
		rubygem-highline>=1.7:devel/rubygem-highline

USES=		gem shebangfix
NO_ARCH=	yes
USE_RUBY=	yes
SHEBANG_FILES=	tools/regem.sh
SHEBANG_LANG=	sh
sh_OLD_CMD=	/bin/bash
sh_CMD=		/bin/sh

PLIST_FILES=	bin/eyaml

.include <bsd.port.mk>
