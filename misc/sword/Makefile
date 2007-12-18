# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.5.10
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.5/ \
		http://crosswire.org/ftpmirror/pub/sword/source/v1.5/ \
		LOCAL
MASTER_SITE_SUBDIR=	tabthorpe

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A project framework for manipulating Bible texts

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:110
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--without-conf --without-clucene --with-zlib
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800000
BROKEN=		Does not compile under 8.X
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
	@(cd ${WRKSRC} && ${GMAKE} install_config)
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

register:
	@(cd ${WRKSRC} && ${GMAKE} register)

.include <bsd.port.post.mk>
