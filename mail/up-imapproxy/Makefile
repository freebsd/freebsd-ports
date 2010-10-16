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

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	A caching IMAP proxy server

USE_AUTOTOOLS=	autoheader:268

USE_RC_SUBR=	imapproxyd.sh
DOCS=		COPYING ChangeLog README README.debian \
		README.known_issues README.ssl
SBINS=		in.imapproxyd pimpstat

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${SBINS:S,^,${WRKSRC}/bin/,} ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf ${PREFIX}/etc/imapproxyd.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
