PORTNAME=	mdless
PORTVERSION=	2.1.62
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Formatted and highlighted view of Markdown files
WWW=		https://rubygems.org/gems/mdless

LICENSE=	MIT

RUN_DEPENDS=	rubygem-redcarpet>=3.6:textproc/rubygem-redcarpet \
		rubygem-rouge>=4.2:textproc/rubygem-rouge \
		rubygem-tty-screen>=0.8:devel/rubygem-tty-screen \
		rubygem-tty-spinner>=0.8:devel/rubygem-tty-spinner \
		rubygem-tty-which>=0.5:devel/rubygem-tty-which

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mdless

.include <bsd.port.mk>
