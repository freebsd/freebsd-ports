# New ports collection makefile for:	imapfilter
# Date created:        28 July 2002
# Whom:                Lefteris Chatzibarbas <lefcha@hellug.gr>
#
# $FreeBSD$
#

PORTNAME=	imapfilter
PORTVERSION=	1.0.1
CATEGORIES=	mail
MASTER_SITES=	http://imapfilter.hellug.gr/source/

MAINTAINER=	lefcha@hellug.gr
COMMENT=	IMAP mail filtering utility

LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua50

USE_BZIP2=	yes
USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-d ${PREFIX} -s ${DATADIR}

MAN1=		imapfilter.1
MAN5=		imapfilter_config.5
PORTDOCS=	LICENSE NEWS README
PLIST_FILES=	bin/imapfilter \
		${DATADIR:S%${PREFIX}/%%}/interface.lua \
		${DATADIR:S%${PREFIX}/%%}/auxiliary.lua \
		${EXAMPLESDIR:S%${PREFIX}/%%}/sample.config.lua \
		${EXAMPLESDIR:S%${PREFIX}/%%}/sample.extend.lua
PLIST_DIRS=	${DATADIR:S%${PREFIX}/%%} ${EXAMPLESDIR:S%${PREFIX}/%%}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/imapfilter
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} interface.lua \
		auxiliary.lua ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} sample.config.lua \
		sample.extend.lua ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
