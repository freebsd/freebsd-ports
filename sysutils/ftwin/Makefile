# $FreeBSD$

PORTNAME=	ftwin
PORTVERSION=	0.8.5
PORTREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://files.etoilebsd.net/ftwin/ \
		http://download.meroware.org/ftwin/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Useful tool to find duplicate files

LIB_DEPENDS=	libpuzzle.so:${PORTSDIR}/graphics/libpuzzle \
		libapr-1.so:${PORTSDIR}/devel/apr1 \
		libpcre.so:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal automake autoheader
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS+=	--with-puzzle=${LOCALBASE}
PLIST_FILES=	bin/ftwin \
		man/man8/ftwin.8.gz

PORTDOCS=	AUTHORS EXAMPLES TODO CHANGES KNOWN_BUGS VERSION LICENSE README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
