PORTNAME=	pam_mkhomedir
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://portal-to-web.de/pam_mkhomedir/

MAINTAINER=	gremlin@portal-to-web.de
COMMENT=	Create HOME with a PAM module on demand

USES=		uidfix
SUB_FILES=	pkg-message

PLIST_FILES=	lib/pam_mkhomedir.so \
		lib/pam_mkhomedir.so.2 \
		share/man/man8/pam_mkhomedir.8.gz

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

.if defined(WITH_PROFILE)
PLIST_FILES+=	lib/libpam_mkhomedir_p.a
MAKE_ARGS+=	PROFILE=yes
WITH_STATIC=	yes
.else
MAKE_ARGS+=	MK_PROFILE=no
.endif

.if defined(WITH_STATIC)
PLIST_FILES+=	lib/libpam_mkhomedir.a
.else
MAKE_ARGS+=	MK_INSTALLLIB=no
.endif

pre-everything::

.if !defined(WITH_PROFILE) || !defined(WITH_STATIC)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "All definable build options"
	@${ECHO_CMD} "---------------------------"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WITH_PROFILE=yes          Build with static lib with profile"
	@${ECHO_CMD} "WITH_STATIC=yes           Build with static lib"
	@${ECHO_CMD} ""
.endif

.include <bsd.port.mk>
