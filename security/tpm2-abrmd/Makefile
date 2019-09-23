# $FreeBSD$

PORTNAME=	tpm2-abrmd
DISTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/tpm2-software/tpm2-abrmd/releases/download/${DISTVERSION}/

MAINTAINER=	tstruk@gmail.com
COMMENT=	TPM2 Access Broker & Resource Manager Deamon

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtss2-esys.so:security/tpm2-tss \
		libgio-2.0.so:devel/glib20
RUN_DEPENDS=	dbus-daemon:devel/dbus

USES=		gmake libtool pkgconfig gnome
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_RC_SUBR=	tpm2-abrmd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbuspolicydir=${PREFIX}/etc/dbus-1/system.d

GROUPS=		_tss
USERS=		_tss

SUB_LIST=	DBUS_DAEMON=dbus

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/systemd/system-preset/tpm2-abrmd.preset
	@${RM} ${STAGEDIR}${PREFIX}/lib/systemd/system/tpm2-abrmd.service
	@${RM} ${STAGEDIR}${PREFIX}/share/dbus-1/system-services/com.intel.tss2.Tabrmd.service
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/systemd/system
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/systemd/system-preset
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/systemd
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/system-services
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/dbus-1

.include <bsd.port.mk>
