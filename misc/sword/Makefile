# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	${SWORD_PORTNAME}
PORTVERSION=	${SWORD_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${SWORD_MASTER_SITES}
MASTER_SITE_SUBDIR=	${SWORD_MASTER_SITE_SUBDIR}
DISTNAME=	${SWORD_DISTNAME}

MAINTAINER=	wvengen@stack.nl
COMMENT=	A project framework for manipulating Bible texts

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--program-transform-name="" --without-conf

.if defined(WITH_INSTALLMGR)
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-installmgr
PLIST_SUB+=	INSTALLMGR=""
.else
CONFIGURE_ARGS+=	--disable-installmgr
PLIST_SUB+=	INSTALLMGR="@comment "

.include "${.CURDIR}/Makefile.common"

pre-everything::
	@${ECHO_CMD} "Define WITH_INSTALLMGR to include the installmanager (curl)"
.endif

post-install: register
.if !exists(${PREFIX}/etc/sword.conf)
	@${ECHO_CMD} "[Install]" >${PREFIX}/etc/sword.conf
	@${ECHO_CMD} "DataPath=${DATADIR}/" >>${PREFIX}/etc/sword.conf
	@${ECHO_CMD} "Config file installed in ${PREFIX}/etc/sword.conf"
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
.if !exists(${PREFIX}/share/sword/mods.d/globals.conf)
	@${MKDIR} ${PREFIX}/share/sword/mods.d
	@${ECHO_CMD} "[Globals]" >${PREFIX}/share/sword/mods.d/globals.conf
	@${ECHO_CMD} "" >>${PREFIX}/share/sword/mods.d/globals.conf
	@${ECHO_CMD} "Global sword runtime settings installed in"
	@${ECHO_CMD} "       ${PREFIX}/share/sword/mods.d/globals.conf
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

register:
.if !defined(BATCH)
	@${ECHO} "Do you want to help the authors of SWORD to keep track of how many"
	@${ECHO} -n "people use this program and register now ? [y/n] "
	@read answer; \
	 if [ x$$answer = xy -o x$$answer = xY ]; then \
		(cd ${WRKSRC}; ${GMAKE} register;); \
	 fi
.endif

.include <bsd.port.mk>
