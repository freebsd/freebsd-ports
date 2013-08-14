# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	imapproxy
PORTVERSION=	1.2.7
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/squirrelmail/imap_proxy/${PORTVERSION}
PKGNAMEPREFIX=	up-
DISTNAME=	squirrelmail-imap_proxy-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Caching IMAP proxy server

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOVECOT DOCS
DOVECOT_DESC=	Use with dovecot2

USE_BZIP2=	yes
USES=	pathfix
USE_OPENSSL=	yes
USE_AUTOTOOLS=	autoheader
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

USE_RC_SUBR=	imapproxyd

SUB_FILES=	pkg-message

DOCS=		ChangeLog README README.debian README.known_issues README.ssl
SBIN=		in.imapproxyd pimpstat

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOVECOT}
SUB_LIST+=	DOVECOT="dovecot"
RUN_DEPENDS+=	dovecot>=1.0:${PORTSDIR}/mail/dovecot2
.else
SUB_LIST+=	DOVECOT=""
.endif

do-install:
.for i in ${SBIN}
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${i} ${PREFIX}/sbin)
.endfor
	(cd ${WRKSRC}/scripts && ${INSTALL_DATA} imapproxy.conf \
		${PREFIX}/etc/imapproxyd.conf.sample)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
