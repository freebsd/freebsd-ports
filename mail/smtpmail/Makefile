# New ports collection makefile for:  	smtpmail
# Date created:        	25.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	smtpmail
PORTVERSION=	0.4.2
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/${PORTNAME}/smtpmail.pkg/0.4.2/ \
		http://voodoo.oberon.net/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Tool to send the mails over remote smtp server

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin

.include <bsd.port.mk>
