# New ports collection makefile for:	DeleGate
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	delegate
PORTVERSION=	9.5.6
CATEGORIES=	net www
MASTER_SITES=	ftp://www.delegate.org/pub/DeleGate/ \
		ftp://ftp.delegate.org/pub/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	nivo+kw+ports.bfa274@is-root.com
COMMENT=	General purpose TCP/IP proxy system

IS_INTERACTIVE=	YES
PORTDOCS=	Manual.htm tutor-jp.htm tutor-en.htm
PLIST_FILES=	sbin/delegated etc/rc.d/delegated.sh-dist

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
