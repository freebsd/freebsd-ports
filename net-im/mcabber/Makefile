# New ports collection makefile for:	mcabber
# Date created:		2005-10-05
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	mcabber
PORTVERSION=	0.7.6
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/ \
		http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Small Jabber console client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=	yes

LDFLAGS+=	-lcrypto

MAN1=		mcabber.1
PLIST_FILES=	bin/mcabber %%EXAMPLESDIR%%/mcabberrc
PLIST_DIRS=	%%EXAMPLESDIR%%

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${EXAMPLESDIR}/mcabberrc

.include <bsd.port.mk>
