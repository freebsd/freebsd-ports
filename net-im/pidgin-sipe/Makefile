# Created by: John Prather
# $FreeBSD$

PORTNAME=	pidgin-sipe
PORTVERSION=	1.18.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF/sipe/sipe/${DISTNAME}

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	Plugin for Pidgin to provide LCS/OCS connectivity

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnss3.so:security/nss \
		libpurple.so:net-im/libpurple
RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README TODO

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		OCS2005 KRB5 DOCS NLS
OPTIONS_SUB=		yes

OSC2005_DESC=		Message timeout for OCS2005
OSC2005_CONFIGURE_ENABLE=	ocs2005-message-hack
KRB5_DESC=		With Kerberos5
KRB5_CONFIGURE_WITH=	krb5
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

CONFIGURE_ARGS+=	--enable-purple \
			--disable-telepathy

post-patch:
	@${REINPLACE_CMD} 's/LDLAGS/LDFLAGS/' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
