# New ports collection makefile for:	postfix-policyd-sf
# Date created:				2005-08-02
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	policyd
PORTVERSION=	1.82
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/1.x%20%28Old%20Stable%29/v${PORTVERSION} \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/

PKGNAMEPREFIX=	postfix-
PKGNAMESUFFIX=	-sf

MAINTAINER=	kiwi@oav.net
COMMENT=	Anti-spam plugin for Postfix (written in C)

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	policyd

REALNAME=	${PKGNAME:C/-${PORTVERSION}.*//}

SUB_LIST+=	REALNAME=${REALNAME}

ALL_TARGET=	linux

DOCS=		ChangeLog ChangeLog.1 README LICENSE TODO DATABASE.mysql \
		doc/whitelist.sql doc/support.txt doc/blacklist_helo.sql
PORTDOCS=	${DOCS:C/.*\///}

PLIST_FILES=	sbin/${REALNAME}-cleanup \
		sbin/${REALNAME}-stats \
		sbin/${REALNAME} \
		etc/${REALNAME}.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's,policyd.pid,postfix-policyd-sf.pid,' \
		${WRKSRC}/policyd.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cleanup ${PREFIX}/sbin/${REALNAME}-cleanup
	${INSTALL_PROGRAM} ${WRKSRC}/stats ${PREFIX}/sbin/${REALNAME}-stats
	${INSTALL_PROGRAM} ${WRKSRC}/policyd ${PREFIX}/sbin/${REALNAME}
	${INSTALL_DATA} ${WRKSRC}/policyd.conf ${PREFIX}/etc/${REALNAME}.conf.sample
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	cd ${WRKSRC}&&${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
