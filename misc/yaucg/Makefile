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
MASTER_SITES=	# http://home.balcab.ch/joelle.wiesmann/secuserv/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bash Script which will get you the today's Userfriendly.org Picture

DEPRECATED=	"master site disappeared, script probably broken"
EXPIRATION_DATE=2005-06-01

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		bash:${PORTSDIR}/shells/bash2

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
STRIP=		# empty

PLIST_FILES=	bin/userfriendly.sh
PORTDOCS=	changelog license readme todo

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/grepper/userfriendly.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
