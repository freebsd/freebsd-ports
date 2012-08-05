# New ports collection makefile for:	imapproxy
# Date created:		11.05.04
# Whom:			Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	imapproxy
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.univie.ac.at/applications/www.imapproxy.org/downloads/
PKGNAMEPREFIX=	up-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A caching IMAP proxy server

USE_AUTOTOOLS=	autoheader

USE_RC_SUBR=	imapproxyd
DOCS=		COPYING ChangeLog README README.debian \
		README.known_issues README.ssl
SBINS=		in.imapproxyd pimpstat

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}

OPTIONS_DEFINE=	DOVECOT DOCS
DOVECOT_DESC=	Use with dovecot2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOVECOT}
SUB_LIST+=	DOVECOT="dovecot"
RUN_DEPENDS+=	dovecot>=1.0:${PORTSDIR}/mail/dovecot2
.else
SUB_LIST+=	DOVECOT=""
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${SBINS:S,^,${WRKSRC}/bin/,} ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
