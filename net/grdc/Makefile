# New ports collection makefile for:	grdc
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	grdc
PORTVERSION=	0.5.1
CATEGORIES=	net gnome
MASTER_SITES=	SF

MAINTAINER=	ports@logvinov.com
COMMENT=	GTK+/GNOME remote desktop client

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

OPTIONS=	VNC	"Build with VNC protocol support"	off \
		SSH	"Build with SSH tunneling support"	off \
		GCRYPT	"Build with libgcrypt support (only with SSH)"	off

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix glib20 gtk20
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITH_VNC)
LIB_DEPENDS+=	vncclient.0:${PORTSDIR}/net/libvncserver
.endif

.if defined(WITH_SSH)
LIB_DEPENDS+=	ssh.2:${PORTSDIR}/security/libssh
.if defined(WITH_GCRYPT)
LIB_DEPENDS+=	gcrypt.16:${PORTSDIR}/security/libgcrypt
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Exec=grdc|Exec=${PREFIX}/bin/grdc|' \
		${WRKSRC}/src/grdc.desktop.in

.include <bsd.port.post.mk>
