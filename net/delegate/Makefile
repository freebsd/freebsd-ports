# New ports collection makefile for:	DeleGate
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	delegate
PORTVERSION=	9.9.7
CATEGORIES=	net www
MASTER_SITES=	http://www.chifeng.name/dist/delegate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	chifeng@gmail.com
COMMENT=	General purpose TCP/IP proxy system

IS_INTERACTIVE=	YES
PORTDOCS=	HowToDG.html Manual.htm jpconv.htm tutor-jp.htm tutor-en.htm COPYRIGHT
PLIST_FILES=	sbin/delegated etc/rc.d/delegated.sh-dist
SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR}

# Strip breaks binary checksumming
STRIP=

post-extract:
	@cd ${WRKSRC} && ${MV} COPYRIGHT doc/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/delegated.sh \
	   ${PREFIX}/etc/rc.d/delegated.sh-dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
