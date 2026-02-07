PORTNAME=	dahdi
PORTVERSION=	${DAHDI_VERSION:S/-//g}
PORTREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	LOCAL/fjoe
DISTNAME=	${PORTNAME}-freebsd-complete-${DAHDI_VERSION}+${DAHDI_TOOLS_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DAHDI userland utilities and libraries
WWW=		http://www.asterisk.org/dahdi/

LIB_DEPENDS=	libnewt.so:devel/newt

DAHDI_VERSION=		2.4.0-rc5
DAHDI_TOOLS_VERSION=	2.4.0-rc1

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake
CONFIGURE_ARGS=	--with-dahdi=../freebsd --sysconfdir=${PREFIX}/etc --with-newt=${LOCALBASE}
CONFIGURE_ENV=	WGET=/usr/bin/fetch
WRKSRC=		${WRKDIR}/${DISTNAME}/tools
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
MAKE_ENV=	HOST_CC=${CC}

CONFLICTS=	zaptel

PIE_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,g'\
		${WRKSRC}/dahdi_cfg.c ${WRKSRC}/fxotune.c\
		${WRKSRC}/doc/dahdi_cfg.8 ${WRKSRC}/doc/fxotune.8

post-install:
	@${ECHO_CMD} "==> Installing dahdi-kmod userland includes"
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/dahdi/compat
	@for i in `${MAKE} -C ${WRKSRC}/../freebsd/freebsd/dahdi -DPRINT_INCS -V INCS`; do\
		${ECHO_CMD} "Installing $$i";\
		${INSTALL_DATA} ${WRKSRC}/../freebsd/include/dahdi/$$i ${STAGEDIR}${PREFIX}/include/dahdi/$$i;\
	done

.include <bsd.port.mk>
