# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.org/download/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAP/SMS gateway

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		tar:bzip2 gmake
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cflags="${CPPFLAGS}" --with-libs="${LDFLAGS}" \
		--enable-pcre=yes --enable-docs=no --with-malloc=native \
		--enable-start-stop-daemon=no --without-sdb --without-oracle \
		--without-sqlite2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3

SQLITE3_USE=	SQLITE=3
SQLITE3_CONFIGURE_WITH=	sqlite3

MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql

PGSQL_USE=	PGSQL=yes
PGSQL_CONFIGURE_WITH=	pgsql

post-install:
.for filename in wapkannel.conf smskannel.conf
	${INSTALL_DATA} ${WRKSRC}/gw/${filename} \
		${STAGEDIR}${PREFIX}/etc/${filename}.sample
.endfor
.for filename in mtbatch seewbmp wmlsc wmlsdasm
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${filename}
.endfor
.for filename in bearerbox run_kannel_box smsbox wapbox
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${filename}
.endfor

.include <bsd.port.mk>
