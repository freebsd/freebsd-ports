# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	opennx
PORTVERSION=	0.16.0.725
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CI-source

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open source drop in replacement for NoMachine\'s NX client

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		smbclient:${PORTSDIR}/net/samba-libsmbclient \
		cups:${PORTSDIR}/print/cups-base

WRKSRC=		${WRKDIR}/${PORTNAME}-0.16

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	xmu
USE_WX=		2.8+
WX_UNICODE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include

MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

NO_PACKAGE=	must generate a fresh private key at install time

SSH_KEYGEN?=	ssh-keygen

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--disable-nls --localedir=/dev/null
PLIST_SUB+=	NLS="@comment "
.else
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

# do not use default private key included with tarball
post-patch:
	@${RM} ${WRKSRC}/share/keys/server.id_dsa.key
	@${SSH_KEYGEN} -N '' -b 2048 -q -f ${WRKSRC}/share/keys/server.id_dsa.key
	@${REINPLACE_CMD} 's|/usr/NX/bin/||' \
		${WRKSRC}/extres/xdg/innovidata-opennx.desktop \
		${WRKSRC}/extres/xdg/innovidata-opennx-admin.desktop \
		${WRKSRC}/extres/xdg/innovidata-opennx-wizard.desktop
	@${RM} ${WRKSRC}/extres/xdg/*.bak

post-install:
	@${CHMOD} 440 ${PREFIX}/share/keys/server.id_dsa.key

.include <bsd.port.mk>
