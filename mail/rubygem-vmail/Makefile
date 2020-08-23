# Created by: Hsin-Han You <hhyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	vmail
PORTVERSION=	2.9.8
PORTREVISION=	2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	Vim interface to Gmail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-highline1>=1.6.1:devel/rubygem-highline1 \
		rubygem-mail>=2.2.12:mail/rubygem-mail \
		rubygem-sequel>=3.24.1:devel/rubygem-sequel \
		rubygem-sqlite3>=1.3.3:databases/rubygem-sqlite3 \
		rubygem-versionomy>=0.4.4:devel/rubygem-versionomy \
		vim:editors/vim-console

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/vmail bin/vmail_client bin/vmailsend

.include <bsd.port.mk>
