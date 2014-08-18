# Created by: Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	xf-spf
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail-smtpextfork/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SPF checker for Qmail's SMTPEXTFORK patch

LIB_DEPENDS=	libspf2.so:${PORTSDIR}/mail/libspf2

USES=		qmail tar:bzip2
USE_GCC=	any
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}
PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX}

PORTDOCS=	README TODO CHANGELOG COPYRIGHT

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
