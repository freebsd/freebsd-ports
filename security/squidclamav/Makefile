# New ports collection makefile for:	squidclamav
# Date created:		2008-06-02
# Whom: 		Laurent LEVIER <llevier@argosnet.com>
#
# $FreeBSD$
#

PORTNAME=	squidclamav
PORTVERSION=	4.0
CATEGORIES=	security
MASTER_SITES=	http://www.samse.fr/GPL/squidclamav/ \
		http://www.darold.net/projects/squidclamav/

MAINTAINER=	llevier@argosnet.com
COMMENT=	Squid interface to ClamAV

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/squidclamav etc/squidclamav.conf.dist

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/squidclamav ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/squidclamav.conf.dist ${PREFIX}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
