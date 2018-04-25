# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	imapproxy
PORTVERSION=	1.2.7
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SF/squirrelmail/imap_proxy/${PORTVERSION}
PKGNAMEPREFIX=	up-
DISTNAME=	squirrelmail-imap_proxy-${PORTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Caching IMAP proxy server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf tar:bzip2 ncurses pathfix ssl

OPTIONS_DEFINE=	DOVECOT DOCS

DOVECOT_DESC=	Use with dovecot2
DOVECOT_RUN_DEPENDS=	dovecot:mail/dovecot

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

USE_RC_SUBR=	imapproxyd

SUB_FILES=	pkg-message

DOCS=		ChangeLog README README.debian README.known_issues README.ssl
SBIN=		in.imapproxyd pimpstat

do-install:
.for i in ${SBIN}
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/sbin)
.endfor
	(cd ${WRKSRC}/scripts && ${INSTALL_DATA} imapproxy.conf \
		${STAGEDIR}${PREFIX}/etc/imapproxyd.conf.sample)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
