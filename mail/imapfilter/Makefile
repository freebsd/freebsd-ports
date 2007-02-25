# New ports collection makefile for:	imapfilter
# Date created:        28 July 2002
# Whom:                Lefteris Chatzibarbas <lefcha@hellug.gr>
#
# $FreeBSD$
#

PORTNAME=	imapfilter
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://imapfilter.hellug.gr/source/

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	IMAP mail filtering utility

USE_BZIP2=	yes
USE_LUA=	5.1
USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-d ${PREFIX} -s ${DATADIR}
CPPFLAGS=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

MAN1=		imapfilter.1
MAN5=		imapfilter_config.5
PORTDOCS=	LICENSE NEWS README
PLIST_FILES=	bin/imapfilter \
		%%DATADIR%%/auxiliary.lua \
		%%DATADIR%%/interface.lua \
		%%EXAMPLESDIR%%/sample.config.lua \
		%%EXAMPLESDIR%%/sample.extend.lua
PLIST_DIRS=	%%DATADIR%% %%EXAMPLESDIR%%

OPTIONS=	PCRE "Enable Perl Compatible Regular Expressions support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_PCRE)
CONFIGURE_ARGS+=	-o pcre=no
.else
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	-o pcre=yes
PLIST_FILES+=	%%DATADIR%%/regex.lua
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(incdirs=).*|\1"${CPPFLAGS}"| ; \
		 s|^(libdirs=).*|\1"${LDFLAGS}"| ; \
		 s|^(mycflags=).*|\1"${CFLAGS}"| ; \
		 s|-llualib||' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/bin/imapfilter
	@${MKDIR} ${DATADIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} interface.lua auxiliary.lua ${DATADIR} && \
		${INSTALL_DATA} sample.config.lua sample.extend.lua \
			${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
