# $FreeBSD$

PORTNAME=	check_memcached_paranoid
PORTVERSION=	0.20131004
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagiosplug/nagiosplug/1.4.16
DISTFILES=	nagios-plugins-1.4.16.tar.gz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Nagios plugin for checking memcached

LIB_DEPENDS=	memcached:${PORTSDIR}/databases/libmemcached
BUILD_DEPENDS=	nagios-plugins>0:${PLUGINS} \
		${EXTRA_DEPENDS} \
		${NONEXISTENT}:${PLUGINS}:build

FILE=		${PORTNAME}.c
PLUGINS=	${PORTSDIR}/net-mgmt/nagios-plugins
NDIR_CMD=	cd ${PLUGINS} && ${MAKE} -VWRKSRC
# Needed for build target on net-mgmt/nagios-plugins
EXTRA_DEPENDS=	automake>0:${PORTSDIR}/devel/automake \
		autoconf>0:${PORTSDIR}/devel/autoconf \
		libtool>0:${PORTSDIR}/devel/libtool \
		gmake:${PORTSDIR}/devel/gmake

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/${FILE} ${WRKSRC}

do-build:
	cd ${WRKSRC}; \
	NDIR=$$(${NDIR_CMD}); \
	${CC} ${CFLAGS} -DLOCALEDIR=\"${LOCALBASE}/share/locale\" -D__need_getopt \
		-I$${NDIR} -I$${NDIR}/plugins -I$${NDIR}/gl -I$${NDIR}/lib -I${LOCALBASE}/include \
		-o ${PORTNAME} \
		$${NDIR}/plugins/netutils.o $${NDIR}/plugins/utils.o \
		$${NDIR}/lib/utils_base.o $${NDIR}/gl/getopt.o $${NDIR}/gl/getopt1.o \
		$${NDIR}/gl/sha1.o \
		-L${LOCALBASE}/lib -lintl -lmemcached ${FILE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
