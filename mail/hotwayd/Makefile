# New ports collection makefile for:	hotwayd
# Date created:				29 October 2002
# Whom:					John Nielsen <john@jnielsen.net>
#
# $FreeBSD$
#

PORTNAME=	hotwayd
PORTVERSION=	0.8.4
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	john@jnielsen.net
COMMENT=	A Hotmail -> POP3 gateway

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

MAN1=		hotwayd.1 \
		hotsmtpd.1

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README VERSION
PLIST_FILES=	sbin/hotwayd sbin/hotsmtpd

post-install:	install-doc-files display-message

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
