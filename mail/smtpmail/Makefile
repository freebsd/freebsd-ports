# New ports collection makefile for:  	smtpmail
# Date created:        	25.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	smtpmail
PORTVERSION=	0.4.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://voodoo.oberon.net/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}.pkg/${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Tool to send the mails over remote smtp server

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin

.include <bsd.port.mk>
