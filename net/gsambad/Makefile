# New ports collection makefile for:	gsambad
# Date created:		16 September 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gsambad
PORTVERSION=	0.1.9
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://mange.dynalias.org/linux/${PORTNAME}/

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Gtk2 Frontend for samba daemon

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/net/samba3

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 pkgconfig

PORTDOCS=	AUTHORS README ChangeLog COPYING

post-extract:
	@${CP} ${FILESDIR}/crypt.h ${WRKSRC}/src/

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

post-configure:
	@${REINPLACE_CMD} -e "s:\<crypt.h\>:\"crypt.h\":" ${WRKSRC}/src/functions.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/desktop/net-gsambad.desktop \
		${PREFIX}/share/applications
	@${INSTALL} -d ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/scripts/example.bat ${DATADIR}

.include <bsd.port.mk>
