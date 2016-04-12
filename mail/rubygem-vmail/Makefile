# Created by: Hsin-Han You <hhyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	vmail
PORTVERSION=	2.9.5
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	Vim interface to Gmail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-highline>=1.6.1:devel/rubygem-highline \
		rubygem-mail>=2.2.12:mail/rubygem-mail \
		rubygem-sequel>=3.24.1:devel/rubygem-sequel \
		rubygem-sqlite3>=1.3.3:databases/rubygem-sqlite3 \
		rubygem-versionomy>=0.4.4:devel/rubygem-versionomy \
		vim:editors/vim-lite

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/vmail bin/vmail_client bin/vmailsend

.include <bsd.port.mk>
