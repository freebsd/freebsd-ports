PORTNAME=	mboxgrep
DISTVERSION=	0.7.11
CATEGORIES=	mail
MASTER_SITES=	https://git.datatipp.se/dspiljar/mboxgrep/archive/
DISTNAME=	${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression
WWW=		http://mboxgrep.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		autoreconf:build localbase
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/mboxgrep
INSTALL_TARGET=	install-strip

INFO=		mboxgrep
PLIST_FILES=	bin/mboxgrep man/man1/mboxgrep.1.gz

OPTIONS_DEFINE=	PCRE
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

.include <bsd.port.mk>
