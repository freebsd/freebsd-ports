# New ports collection makefile for:	imapfilter
# Date created:        28 July 2002
# Whom:                Lefteris Chatzibarbas <lefcha@hellug.gr>
#
# $FreeBSD$
#

PORTNAME=	imapfilter
PORTVERSION=	0.8
CATEGORIES=	mail
MASTER_SITES=	http://imapfilter.hellug.gr/source/

MAINTAINER=	lefcha@hellug.gr

USE_OPENSSL=	yes

MAN1=		imapfilter.1
MAN5=		imapfilterrc.5

post-install:
	${STRIP_CMD} $(PREFIX)/bin/imapfilter
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/sample.imapfilterrc ${EXAMPLESDIR}
.endif
	@$(CAT) $(PKGMESSAGE)

.include <bsd.port.mk>
