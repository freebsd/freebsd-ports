# Created by: Hsin-Han You <hhyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	vmail
PORTVERSION=	2.8.6
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	A Vim interface to Gmail

RUN_DEPENDS=	rubygem-mail>=2.2.12:${PORTSDIR}/mail/rubygem-mail \
		rubygem-highline>=1.6.1:${PORTSDIR}/devel/rubygem-highline \
		rubygem-sequel>=3.24.1:${PORTSDIR}/devel/rubygem-sequel \
		rubygem-sqlite3>=1.3.3:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-versionomy>=0.4.4:${PORTSDIR}/devel/rubygem-versionomy \
		${LOCALBASE}/bin/vim:${PORTSDIR}/editors/vim-lite

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/vmail bin/vmail_client bin/vmailsend

.include <bsd.port.mk>
