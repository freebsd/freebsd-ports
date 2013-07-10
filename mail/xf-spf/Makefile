# Created by: Felippe de Meirelles Motta <lippe@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	xf-spf
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail-smtpextfork/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	SPF checker for Qmail's SMTPEXTFORK patch

LIB_DEPENDS+=	spf2.3:${PORTSDIR}/mail/libspf2

USES=		qmail
USE_BZIP2=	yes
USE_GCC=	any
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}
PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX}

PORTDOCS=	README TODO CHANGELOG COPYRIGHT

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
