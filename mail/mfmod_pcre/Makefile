PORTNAME=	mfmod_pcre
PORTVERSION=	1.1.1
CATEGORIES=	mail
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/ \
		http://download.gnu.org.ua/pub/alpha/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	PCRE support loadable module for mailfromd
WWW=		https://puszcza.gnu.org.ua/projects/mfmod_pcre/

LICENSE=	GPLv3+

BUILD_DEPENDS=	${LOCALBASE}/include/mailfromd/mfmod.h:mail/mailfromd
LIB_DEPENDS=	libmailutils.so:mail/mailutils libpcre2-8.so:devel/pcre2

USES=		libtool localbase
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		${PORTNAME}
PLIST_FILES=	lib/mailfromd/mfmod_pcre.so share/mailfromd/pcre.mfl
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
