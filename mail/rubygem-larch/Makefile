# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	larch
PORTVERSION=	1.1.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Larch copies messages from one IMAP server to another

LICENSE=	GPLv2

#		rubygem-sequel3>=3.14:devel/rubygem-sequel3 \
RUN_DEPENDS=	rubygem-highline>=1.5:devel/rubygem-highline \
		rubygem-sequel>=3.14:devel/rubygem-sequel \
		rubygem-sqlite3>=1.3:databases/rubygem-sqlite3 \
		rubygem-trollop>=1.13:devel/rubygem-trollop

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/larch

.include <bsd.port.mk>
