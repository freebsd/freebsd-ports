# New ports collection makefile for:	imapfilter
# Date created:        28 July 2002
# Whom:                Lefteris Chatzibarbas <lefcha@hellug.gr>
#
# $FreeBSD$
#

PORTNAME=	imapfilter
PORTVERSION=	0.9.6
CATEGORIES=	mail
MASTER_SITES=	http://imapfilter.hellug.gr/source/

MAINTAINER=	lefcha@hellug.gr
COMMENT=	IMAP mail filtering utility

USE_BZIP2=	yes
USE_OPENSSL=	yes

MAN1=		imapfilter.1
MAN5=		imapfilterrc.5
PORTDOCS=	LICENSE NEWS README
PLIST_FILES=	bin/imapfilter ${EXAMPLESDIR:S%${PREFIX}/%%}/sample.imapfilterrc
PLIST_DIRS=	${EXAMPLESDIR:S%${PREFIX}/%%}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/imapfilter
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
