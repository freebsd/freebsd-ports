# New ports collection makefile for:	mcabber
# Date created:		2005-10-05
# Whom:			vsevolod
#
# $FreeBSD$
#

PORTNAME=	mcabber
PORTVERSION=	0.9.3
CATEGORIES=	net-im
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Small Jabber console client

LIB_DEPENDS=	gpgme.17:${PORTSDIR}/security/gpgme \
		aspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --with-ssl --enable-aspell=yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		mcabber.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
BROKEN=	Unicoded ncurses require 5.3
.endif

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$"$${datadir}"|"$${datadir}"|;s|-O2||'\
		${WRKSRC}/configure ${WRKSRC}/*/configure

post-install:
	@${INSTALL} -d ${PREFIX}/share/applications/ ${EXAMPLESDIR}/
	@${INSTALL} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@${CP} -R ${WRKSRC}/contrib ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${EXAMPLESDIR}/mcabberrc

.include <bsd.port.post.mk>
