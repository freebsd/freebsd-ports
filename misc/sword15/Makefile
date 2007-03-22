# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.5.9
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.5/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bibletime

MAINTAINER=	thomas@goodking.ca
COMMENT=	A project framework for manipulating Bible texts

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:19
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--without-conf --without-clucene
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= 700000 )
BROKEN=	does not build on 7.X
.endif

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
		${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${PREFIX}/share/sword/mods.d
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

.include <bsd.port.post.mk>
