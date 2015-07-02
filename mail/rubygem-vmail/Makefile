# Created by: Hsin-Han You <hhyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	vmail
PORTVERSION=	2.8.7
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	Vim interface to Gmail

LICENSE=	MIT

RUN_DEPENDS=	rubygem-highline>=1.6.1:${PORTSDIR}/devel/rubygem-highline \
		rubygem-mail>=2.2.12:${PORTSDIR}/mail/rubygem-mail \
		rubygem-sequel>=3.24.1:${PORTSDIR}/devel/rubygem-sequel \
		rubygem-sqlite3>=1.3.3:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-versionomy>=0.4.4:${PORTSDIR}/devel/rubygem-versionomy \
		${LOCALBASE}/bin/vim:${PORTSDIR}/editors/vim-lite

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/vmail bin/vmail_client bin/vmailsend

.include <bsd.port.mk>
