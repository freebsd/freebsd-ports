# New ports collection makefile for:	gsambad
# Date created:		16 September 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gsambad
PORTVERSION=	0.1.9
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://mange.dynalias.org/linux/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 Frontend for samba daemon

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba34

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 pkgconfig

PORTDOCS=	AUTHORS README ChangeLog COPYING

post-extract:
	@${CP} ${FILESDIR}/crypt.h ${WRKSRC}/src/

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4

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
