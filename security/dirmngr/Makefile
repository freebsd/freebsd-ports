# New ports collection makefile for:	dirmngr
# Date created:		06 Feb 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	dirmngr
PORTVERSION=	0.4.5
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		http://tigress.com/lofi/:lofi/
MASTER_SITE_SUBDIR=	alpha/aegypten
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		common.tar.gz:lofi

MAINTAINER=	lofi@freebsd.org
COMMENT=	A client for managing and downloading certificate revocation lists

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2 \
		gcrypt.6:${PORTSDIR}/security/libgcrypt \
		ksba.7:${PORTSDIR}/security/libksba

USE_OPENLDAP=	yes
USE_GETOPT_LONG=yes
USE_AUTOMAKE_VER=	15
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-included-gettext=no
INFO=		dirmngr
PLIST_FILES=	bin/dirmngr

.include <bsd.port.pre.mk>

post-extract:
	${MV} ${WRKDIR}/common ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	cd ${WRKSRC}; ./autogen.sh

.include <bsd.port.post.mk>
