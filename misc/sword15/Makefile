# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.5.7
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.5/ \
	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
# 1.5.7a version fixes some build problems. Since there was no FreeBSD
# version of 1.5.7 it's really no problem to put the a here. WRKSRC is also
# just work/sword-1.5.7
DISTFILES=	${DISTNAME}a${EXTRACT_SUFX}

MAINTAINER=	wvengen@stack.nl
COMMENT=	A project framework for manipulating Bible texts

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--without-conf
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--without-curl
PLIST_SUB+=	INSTALLMGR="@comment "
.else
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl
PLIST_SUB+=	INSTALLMGR=""

pre-everything::
	@${ECHO_CMD} "Define WITHOUT_CURL to disable remote fetch (curl) support in the installmanager"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} -p ${PREFIX}/share/sword/mods.d
.if !exists(${PREFIX}/etc/sword.conf)
	@(cd ${WRKSRC} && make install_config)
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

register:
	@(cd ${WRKSRC} && make register)

.include <bsd.port.mk>
