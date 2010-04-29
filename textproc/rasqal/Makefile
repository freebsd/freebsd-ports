# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/librdf/${PORTNAME}/${PORTVERSION} \
		http://librdf.org/dist/source/


MAINTAINER=	kde@FreeBSD.org
COMMENT=	A high-level interface for RDF

LIB_DEPENDS=	raptor.2:${PORTSDIR}/textproc/raptor

USE_BDB=	yes
WITH_BDB_HIGHEST=	yes
INVALID_BDB_VER=2
USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-raptor=system \
		--with-rasqal=internal \
		--with-threestore=no \
		--with-sqlite=no

USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

MAN1=		rasqal-config.1 rdfproc.1 redland-config.1 \
		redland-db-upgrade.1 roqet.1
MAN3=		librasqal.3 redland.3

OPTIONS+=	MYSQL "Use MySQL instead of BDB" off
OPTIONS+=	MPFR  "Use MPFR library for decimals (implies GMP)" off
OPTIONS+=	GMP   "Use Gnu MP library for decimals" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--with-mysql=no
PLIST_SUB+=	MYSQL="@comment "
.endif

# Set to mpfr if MPFR is on, gmp if only GMP is on and none if neither.
# This guards against $user setting both GMP and MPFR, since we can't be
# very verbose in explaining our options.
.if defined(WITH_MPFR)
CONFIGURE_ARGS+=	--with-decimal=mpfr
LIB_DEPENDS+=	mpfr.3:${PORTSDIR}/math/mpfr
.elif defined(WITH_GMP)
CONFIGURE_ARGS+=	--with-decimal=gmp
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.else
CONFIGURE_ARGS+=	--with-decimal=none
.endif

pre-everything::
	@${ECHO_CMD} "You can choose BDB version by setting WITH_BDB_VER to one off:"
	@${ECHO_CMD} "3 40 41 42 43 44 3+ 40+ 41+ 42+ 43+ 44+ (current: ${BDB_VER})"
.	if defined(WITH_MYSQL)
	@${ECHO_CMD} "MySQL version to be used: ${MYSQL_VER}"
	@${ECHO_CMD} "If you don't have MySQL installed you can stop the build now"
	@${ECHO_CMD} "and set WITH_MYSQL_VER to the desired version"
.	endif

.include <bsd.port.post.mk>
