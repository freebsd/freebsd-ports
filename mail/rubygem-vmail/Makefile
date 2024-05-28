PORTNAME=	vmail
PORTVERSION=	2.9.8
PORTREVISION=	3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	Vim interface to Gmail
WWW=		https://danielchoi.com/software/vmail.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-highline1>=1.6.1<2:devel/rubygem-highline1 \
		rubygem-mail>=2.2.12,2<3,2:mail/rubygem-mail \
		rubygem-sequel>=3.24.1:devel/rubygem-sequel \
		rubygem-sqlite31>=1.3.3<2:databases/rubygem-sqlite31 \
		rubygem-versionomy>=0.4.4<1:devel/rubygem-versionomy \
		vim:editors/vim

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/vmail bin/vmail_client bin/vmailsend

.include <bsd.port.mk>
