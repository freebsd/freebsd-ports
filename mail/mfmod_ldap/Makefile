PORTNAME=	mfmod_ldap
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/ \
		http://download.gnu.org.ua/pub/alpha/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	LDAP support loadable module for mailfromd
WWW=		https://puszcza.gnu.org.ua/projects/mfmod_ldap/

LICENSE=	GPLv3+

BUILD_DEPENDS=	${LOCALBASE}/include/mailfromd/mfmod.h:mail/mailfromd

USES=		ldap libtool localbase makeinfo
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		${PORTNAME}
PLIST_FILES=	lib/mailfromd/mfmod_ldap.so share/mailfromd/ldap.mfl
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,g' \
		${WRKSRC}/mfmod_ldap.c ${WRKSRC}/doc/mfmod_ldap.texi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
