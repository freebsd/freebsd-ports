# Created by: Lefteris Chatzibarbas <lefcha@hellug.gr>
# $FreeBSD$

PORTNAME=	imapfilter
PORTVERSION=	2.5.6
#PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://www.gegenunendlich.de/distfiles/ \
		GH

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	IMAP mail filtering utility

LICENSE=	MIT

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_LUA=	5.1
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes
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

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -Ee ' \
	    s|^(PREFIX =).*|\1${PREFIX}|; \
	    s|^(MYCFLAGS =).*|\1${CPPFLAGS}|; \
	    s|^(MYLDFLAGS =).*|\1${LDFLAGS}|; \
	    s|^(BINDIR =).*|\1${PREFIX}/bin|; \
	    s|^(SHAREDIR =).*|\1${DATADIR}|; \
	    s|^(MANDIR =).*|\1${MANPREFIX}/man|' \
	    ${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/imapfilter
	@${MKDIR} ${STAGEDIR}/${DATADIR} ${STAGEDIR}/${EXAMPLESDIR}
	cd ${WRKSRC}/samples && \
		${INSTALL_DATA} config.lua extend.lua \
			${STAGEDIR}/${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.post.mk>
