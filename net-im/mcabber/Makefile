# New ports collection makefile for:	mcabber
# Date created:		2005-10-05
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	mcabber
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Small Jabber console client

LIB_DEPENDS=	ncursesw.5:${PORTSDIR}/devel/ncurses

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man --with-ssl
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS=	${CFLAGS}
LDFLAGS+=	-lcrypto -L${LOCALBASE}/lib

MAN1=		mcabber.1

post-patch:
	@${REINPLACE_CMD} -e 's#$$"$${datadir}"#"$${datadir}"#' \
		-e 's/waddnwstr/mvwaddnwstr/g' -e 's!ncursesw/!ncurses/!g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/NCURSESW/NCURSES/' ${WRKSRC}/src/screen.h ${WRKSRC}/src/utf8.h
	@${REINPLACE_CMD} -e 's!ncursesw/!ncurses/!g' ${WRKSRC}/src/screen.h

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/contrib ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${EXAMPLESDIR}/mcabberrc

.include <bsd.port.mk>
