PORTNAME=	policyd
PORTVERSION=	1.82
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/1.x%20%28Old%20Stable%29/v${PORTVERSION}
PKGNAMEPREFIX=	postfix-
PKGNAMESUFFIX=	-sf

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Anti-spam plugin for Postfix (written in C)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake mysql
USE_RC_SUBR=	policyd

ALL_TARGET=	linux

CFLAGS+=	-fcommon

SUB_LIST+=	PKGBASE=${PKGBASE}

PLIST_FILES=	etc/${PKGBASE}.conf.sample \
		sbin/${PKGBASE} \
		sbin/${PKGBASE}-cleanup \
		sbin/${PKGBASE}-stats
PORTDOCS=	${_DOCS:C/.*\///}

OPTIONS_DEFINE=	DOCS

_DOCS=		ChangeLog ChangeLog.1 README TODO DATABASE.mysql \
		doc/whitelist.sql doc/support.txt doc/blacklist_helo.sql

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cleanup ${STAGEDIR}${PREFIX}/sbin/${PKGBASE}-cleanup
	${INSTALL_PROGRAM} ${WRKSRC}/stats ${STAGEDIR}${PREFIX}/sbin/${PKGBASE}-stats
	${INSTALL_PROGRAM} ${WRKSRC}/policyd ${STAGEDIR}${PREFIX}/sbin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/policyd.conf ${STAGEDIR}${PREFIX}/etc/${PKGBASE}.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
