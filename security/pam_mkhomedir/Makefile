# New ports collection makefile for:   pam_mkhomedir
# Date created:                        08 June 2005
# Whom:                                Martin Mersberger
#
# $FreeBSD$
#

PORTNAME=	pam_mkhomedir
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	http://portal-to-web.de/pam_mkhomedir/

MAINTAINER=	gremlin@portal-to-web.de
COMMENT=	Create HOME with a PAM module on demand

MANCOMPRESSED=	yes
MAN8=		pam_mkhomedir.8
SUB_FILES=      pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	Only for 5.0 and above
.endif

.if defined(WITH_PROFILE)
PLIST_SUB+=	PROFILE=""
MAKE_ARGS+=	PROFILE=yes
WITH_STATIC=	yes
.else
PLIST_SUB+=	PROFILE="@comment "
MAKE_ARGS+=	NOPROFILE=yes
.endif

.if defined(WITH_STATIC)
PLIST_SUB+=     NOSTATIC=""
.else
MAKE_ARGS+=	NOINSTALLLIB=yes
PLIST_SUB+=	NOSTATIC="@comment "
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
