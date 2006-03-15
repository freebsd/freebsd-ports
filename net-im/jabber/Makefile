# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4.4
CATEGORIES=	net-im
MASTER_SITES=	http://download.jabberd.org/jabberd14/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/
DISTNAME=	${PORTNAME}d-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Online presence and instant messaging server

LIB_DEPENDS=	pth.20:${PORTSDIR}/devel/pth \
		expat.6:${PORTSDIR}/textproc/expat2 \
		idn.16:${PORTSDIR}/dns/libidn

USE_RC_SUBR=	jabberd.sh
SUB_FILES=	pkg-message
USE_GMAKE=	yes

MAN5=		jabber.xml.5
MAN8=		jabberd.8
NOMANCOMPRESS=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--with-libidn=${LOCALBASE} --with-libpth=${LOCALBASE} --localstatedir=/var
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	SSL "Build SSL support" on \
		IPV6 "Use IPV6 code" off \
		MYSQL "Build mysql support" off \
		PGSQL "Build PostgreSQL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
WITH_OPENSSL=yes
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-ssl-legacy=${OPENSSLBASE}
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,libpth/(lib|include),libpth/\1/pth,g; \
			      s,(mysql)/(lib|include),\1/\2/\1,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,postgresql/libpq-fe.h,libpq-fe.h,g' \
		${WRKSRC}/configure \
		${WRKSRC}/xdb_sql/xdb_sql.c

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
