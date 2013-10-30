# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	larch
PORTVERSION=	1.1.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Larch copies messages from one IMAP server to another

RUN_DEPENDS=	rubygem-highline>=1.5:${PORTSDIR}/devel/rubygem-highline \
		rubygem-sequel3>=3.14:${PORTSDIR}/devel/rubygem-sequel3 \
		rubygem-sqlite3>=1.3:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-trollop>=1.13:${PORTSDIR}/devel/rubygem-trollop

PLIST_FILES=	bin/larch

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
