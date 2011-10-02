# Ports collection makefile for:	rubygem-larch
# Date created:				28 June 2011
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	larch
PORTVERSION=	1.1.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Larch copies messages from one IMAP server to another

RUN_DEPENDS=	rubygem-amalgalite>=1.0:${PORTSDIR}/databases/rubygem-amalgalite \
		rubygem-highline>=1.5:${PORTSDIR}/devel/rubygem-highline \
		rubygem-sequel>=3.14:${PORTSDIR}/devel/rubygem-sequel \
		rubygem-trollop>=1.13:${PORTSDIR}/devel/rubygem-trollop

PLIST_FILES=	bin/larch

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
