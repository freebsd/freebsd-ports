# New ports collection makefile for:	hotwayd
# Date created:				29 October 2002
# Whom:					John Nielsen <john@jnielsen.net>
#
# $FreeBSD$
#

PORTNAME=	hotwayd
PORTVERSION=	0.7.4
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hotwayd

MAINTAINER=	john@jnielsen.net
COMMENT=	A Hotmail -> POP3 gateway

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

MAN1=		hotwayd.1

DOC_FILES=	AUTHORS COPYING ChangeLog INSTALL NEWS README VERSION
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

post-install:	install-doc-files display-message

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
