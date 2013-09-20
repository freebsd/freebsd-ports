# Created by: Maxim Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dahdi
PORTVERSION=	${DAHDI_VERSION:S/-//g}
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fjoe
DISTNAME=	${PORTNAME}-freebsd-complete-${DAHDI_VERSION}+${DAHDI_TOOLS_VERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	DAHDI userland utilities and libraries

LIB_DEPENDS=	newt.52:${PORTSDIR}/devel/newt

DAHDI_VERSION=		2.4.0-rc5
DAHDI_TOOLS_VERSION=	2.4.0-rc1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-dahdi=../freebsd --sysconfdir=${PREFIX}/etc --with-newt=${LOCALBASE}
CONFIGURE_ENV=	WGET=/usr/bin/fetch
WRKSRC=		${WRKDIR}/${DISTNAME}/tools
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes

CONFLICTS=	zaptel-[0-9]*

MAN8=	dahdi_cfg.8\
	dahdi_monitor.8\
	dahdi_scan.8\
	dahdi_test.8\
	dahdi_tool.8\
	fxotune.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,g'\
		${WRKSRC}/dahdi_cfg.c ${WRKSRC}/fxotune.c\
		${WRKSRC}/doc/dahdi_cfg.8 ${WRKSRC}/doc/fxotune.8

post-install:
	@${ECHO_CMD} "==> Installing dahdi-kmod userland includes"
	@${MKDIR} ${PREFIX}/include/dahdi/compat
	@for i in `${MAKE} -C ${WRKSRC}/../freebsd/freebsd/dahdi -DPRINT_INCS -V INCS`; do\
		${ECHO_CMD} "Installing $$i";\
		${INSTALL_DATA} ${WRKSRC}/../freebsd/include/dahdi/$$i ${PREFIX}/include/dahdi/$$i;\
	done

.include <bsd.port.mk>
