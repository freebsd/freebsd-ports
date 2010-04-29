# New ports collection makefile for:	nagios-check_memcached_paranoid
# Date created:		29 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	check_memcached_paranoid
PORTVERSION=	0.20091016
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Nagios plugin for checking memcached

LIB_DEPENDS=	memcache:${PORTSDIR}/databases/libmemcache
BUILD_DEPENDS=	nagios-plugins>0:${PLUGINS} \
		${EXTRA_DEPENDS} \
		${NONEXISTENT}:${PLUGINS}:build

PLIST_FILES=	libexec/nagios/${PORTNAME}

FILE=		${PORTNAME}.c
PLUGINS=	${PORTSDIR}/net-mgmt/nagios-plugins
NDIR_CMD=	cd ${PLUGINS} && ${MAKE} -VWRKSRC
# Needed for build target on net-mgmt/nagios-plugins
EXTRA_DEPENDS=	automake>0:${PORTSDIR}/devel/automake19 \
		autoconf>0:${PORTSDIR}/devel/autoconf262 \
		libtool>0:${PORTSDIR}/devel/libtool22 \
		gmake:${PORTSDIR}/devel/gmake

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/${FILE} ${WRKSRC}

do-build:
	cd ${WRKSRC}; \
	NDIR=$$(${NDIR_CMD}); \
	${CC} ${CFLAGS} -DLOCALEDIR=\"${LOCALBASE}/share/locale\" \
		-I$${NDIR} -I$${NDIR}/plugins -I$${NDIR}/gl -I$${NDIR}/lib -I${LOCALBASE}/include \
		-o ${PORTNAME} \
		$${NDIR}/plugins/netutils.o $${NDIR}/plugins/utils.o \
		$${NDIR}/lib/utils_base.o $${NDIR}/gl/getopt.o $${NDIR}/gl/getopt1.o \
		-L${LOCALBASE}/lib -lintl -lmemcache ${FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
