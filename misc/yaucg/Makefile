# New ports collection makefile for:	yaucg
# Date created:			26 August 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	yaucg
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://home.balcab.ch/joelle.wiesmann/secuserv/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	A bash Script which will get you the today's Userfriendly.org Picture

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		bash:${PORTSDIR}/shells/bash2

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
STRIP=		# empty

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/grepper/userfriendly.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in changelog license readme todo
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
