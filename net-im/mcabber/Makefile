# New ports collection makefile for:	mcabber
# Date created:		2005-10-05
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	mcabber
PORTVERSION=	0.7.8
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Small Jabber console client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=	yes

LDFLAGS+=	-lcrypto

MAN1=		mcabber.1

post-patch:
	${REINPLACE_CMD} -e 's#$$"$${datadir}"#"$${datadir}"#' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${EXAMPLESDIR}/mcabberrc

.include <bsd.port.mk>
