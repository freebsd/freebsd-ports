# New ports collection Makefile for: 	osiris
# Date created:				10, February 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	osiris
PORTVERSION=	1.5.2
CATEGORIES=	security
MASTER_SITES=	http://osiris.shmoo.com/data/

MAINTAINER=	ecu@ipv42.net
COMMENT=	File integrity checking, with GDBM and MySQL support

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE} \
			--enable-module=mysql
.else
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm=${LOCALBASE} \
			--with-module-lib=${LOCALBASE}/lib \
			--with-module-includes=${LOCALBASE}/include
.endif

NO_CDROM=	This software can not be sold.

GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=13

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		osiris.1 scale.1

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set WITH_MYSQL to get MySQL support."
	@${ECHO_MSG} ""

post-install:
	${INSTALL_DATA} ${WRKSRC}/configs/osiris-freebsd-4.4.conf \
			${PREFIX}/etc/osiris.conf-sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in docs/manual.html docs/manual.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
