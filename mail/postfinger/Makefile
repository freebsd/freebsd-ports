# New ports collection makefile for: postfinger
# Date created:			16 May 2003
# Whom:				Andrew J. Caines <A.J.Caines@halplant.com>
#
# $FreeBSD$
#

PORTNAME=	postfinger
PORTVERSION=	1.29
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nobandwidth.net/pub/postfix-mudd/postfinger/ \
		ftp://ftp.wl0.org/postfinger/
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION} README
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Postfix Configuration Summary Reporter

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=		yes
WRKSRC=			${WRKDIR}

PLIST_FILES=		bin/postfinger

PORTDOCS=		README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
