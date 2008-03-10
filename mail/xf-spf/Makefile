# New ports collection makefile for:    xf-spf
# Date created:         2007-09-12
# Whom:                 Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	xf-spf
PORTVERSION=	0.2
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail-smtpextfork/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	SPF checker for Qmail's SMTPEXTFORK patch

LIB_DEPENDS+=	spf2.2:${PORTSDIR}/mail/libspf2

USE_QMAIL=	yes
USE_BZIP2=	yes

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}
PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX}

PORTDOCS=	README TODO CHANGELOG COPYRIGHT

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
