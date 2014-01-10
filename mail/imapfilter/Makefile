# Created by: Lefteris Chatzibarbas <lefcha@hellug.gr>
# $FreeBSD$

PORTNAME=	imapfilter
PORTVERSION=	2.5.6
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.gegenunendlich.de/distfiles/ \
		GH

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	IMAP mail filtering utility

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		lua
USE_OPENSSL=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	lefcha
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	e3c8279

PORTDOCS=	LICENSE NEWS README
PLIST_FILES=	bin/imapfilter \
		man/man1/imapfilter.1.gz \
		man/man5/imapfilter_config.5.gz \
		%%DATADIR%%/account.lua \
		%%DATADIR%%/auxiliary.lua \
		%%DATADIR%%/common.lua \
		%%DATADIR%%/mailbox.lua \
		%%DATADIR%%/message.lua \
		%%DATADIR%%/options.lua \
		%%DATADIR%%/regex.lua \
		%%DATADIR%%/set.lua \
		%%EXAMPLESDIR%%/config.lua \
		%%EXAMPLESDIR%%/extend.lua
PLIST_DIRS=	%%DATADIR%% %%EXAMPLESDIR%%
MAKE_ARGS=	PREFIX=${PREFIX} \
		MYCFLAGS="${CPPFLAGS}" \
		MYLDFLAGS="${LDFLAGS}" \
		BINDIR=${PREFIX}/bin \
		SHAREDIR=${DATADIR} \
		MANDIR=${MANPREFIX}/man \
		LIBLUA=-llua-${LUA_VER}

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/imapfilter
	@${MKDIR} ${STAGEDIR}/${DATADIR} ${STAGEDIR}/${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} config.lua extend.lua \
			${STAGEDIR}/${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
