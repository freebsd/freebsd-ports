# New ports collection makefile for:	iceb
# Date created:		20 December 2002
# Whom:			Vadim Chekan <vchekan@softline.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	iceb
PORTVERSION=	5.60
PORTREVISION=	1
CATEGORIES=	ukrainian finance
MASTER_SITES=	http://www.iceb.vinnitsa.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ukrainian accounting system

BROKEN=		Incomplete pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

USE_MYSQL=	yes
WANT_MYSQL_VER=	323
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=13
USE_AUTOCONF_VER=	213
USE_AUTOMAKE_VER=	14
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--with-lang=ua \
		--with-lock-dir=/var/spool/lock \
		--with-config-path=${PREFIX}/etc/iceb \
		--with-lang-path=${PREFIX}/share/nls/uk_UA.KOI8-U
CFLAGS+=	-I${LOCALBASE}/include/mysql -L${LOCALBASE}/lib/mysql
CONFIGURE_ENV=	ICEB_DB_LIB=${LOCALBASE}/lib/mysql

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 503000
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/configure.in

pre-configure:
	${MKDIR} ${PREFIX}/share/nls/uk_UA.KOI8-U

.include <bsd.port.post.mk>
