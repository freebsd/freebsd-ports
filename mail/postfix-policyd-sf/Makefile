# New ports collection makefile for:	postfix-policyd-sf
# Date created:				2005-08-02
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	policyd
PORTVERSION=	1.73
CATEGORIES=	mail
MASTER_SITES=	http://policyd.sourceforge.net/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/
PKGNAMEPREFIX=	postfix-
PKGNAMESUFFIX=	-sf
DISTNAME=	policyd-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Anti-spam plugin for Postfix (written in C)

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	policyd.sh

REALNAME=	${PKGNAME:C/-${PORTVERSION}.*//}

SUB_LIST+=	REALNAME=${REALNAME}

ALL_TARGET=	linux

DOCS=		Changelog.txt README.txt License.txt DATABASE.mysql \
		doc/whitelist.sql doc/support.txt doc/blacklist_helo.sql
PORTDOCS=	*

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
	${MKDIR} ${DOCSDIR}
	for f in ${DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
