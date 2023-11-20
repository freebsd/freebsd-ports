PORTNAME=	mboxgrep
PORTVERSION=	0.7.12a
CATEGORIES=	mail
MASTER_SITES=	https://git.datatipp.se/attachments/5e6a5b31-60b9-4fb3-9674-fe1e292e8fee?dummy=/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression
WWW=		https://mboxgrep.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		autoreconf:build localbase
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		mboxgrep
PLIST_FILES=	bin/mboxgrep man/man1/mboxgrep.1.gz

OPTIONS_DEFINE=	PCRE
OPTIONS_DEFAULT=	PCRE
PCRE_LIB_DEPENDS=	libpcre2-32.so:devel/pcre2
PCRE_CONFIGURE_WITH=	pcre2

.include <bsd.port.mk>
