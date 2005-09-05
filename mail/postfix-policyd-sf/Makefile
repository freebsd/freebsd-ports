# New ports collection makefile for:	policyd-sf
# Date created:				2005-08-02
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	policyd
PORTVERSION=	1.66
CATEGORIES=	mail
MASTER_SITES=	http://policyd.sourceforge.net/
PKGNAMEPREFIX=	postfix-
PKGNAMESUFFIX=	-sf
DISTNAME=	policyd-v${PORTVERSION}

MAINTAINER=	rafan@infor.org
COMMENT=	Anti-spam plugin for Postfix (written in C)

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	policyd.sh

REALNAME=	${PKGNAME:S/-${PORTVERSION}//}

SUB_LIST+=	REALNAME=${REALNAME}

ALL_TARGET=	linux

PORTDOCS=	Changelog.txt README.txt License.txt WHITELIST.sql

PLIST_FILES=	sbin/${REALNAME}-cleanup \
		sbin/${REALNAME} \
		etc/${REALNAME}.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cleanup ${PREFIX}/sbin/${REALNAME}-cleanup
	${INSTALL_PROGRAM} ${WRKSRC}/policyd ${PREFIX}/sbin/${REALNAME}
	${INSTALL_DATA} ${WRKSRC}/policyd.conf ${PREFIX}/etc/${REALNAME}.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
