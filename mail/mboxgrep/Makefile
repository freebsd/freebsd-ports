PORTNAME=	mboxgrep
DISTVERSION=	0.7.13
CATEGORIES=	mail
MASTER_SITES=	https://github.com/dspiljar/mboxgrep/releases/download/${DISTVERSION}/ \
		https://git.datatipp.se/dspiljar/mboxgrep/releases/download/${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression
WWW=		https://mboxgrep.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		localbase
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

INFO=		mboxgrep
PLIST_FILES=	bin/mboxgrep share/man/man1/mboxgrep.1.gz

OPTIONS_DEFINE=	PCRE
OPTIONS_DEFAULT=	PCRE
PCRE_LIB_DEPENDS=	libpcre2-32.so:devel/pcre2
PCRE_CONFIGURE_OFF=	--without-pcre2

.include <bsd.port.mk>
