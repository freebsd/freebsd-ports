# New ports collection makefile for:   bmf
# Date created:        15 March 2003
# Whom:                Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmf
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	A fast Bayesian Mail Filter compatible with maildrop and procmail

.if defined(WITH_BDB41)
LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ENV+=	DB_LIBNAME=-ldb41
.elif defined(WITH_BDB4)
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ENV+=	DB_LIBNAME=-ldb4
.elif defined(WITH_BDB3)
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ENV+=	DB_LIBNAME=-ldb3
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-package

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--debug=yes
.endif

MAN1= bmf.1 bmfconv.1

pre-everything::
	@${ECHO} ""
	@${ECHO} "${PORTNAME} has several tunables available:"
	@${ECHO} ""
	@${ECHO} "	WITH_BDB4		Builds with BDB4 support"
	@${ECHO} "	WITH_BDB41		Builds with BDB4.1 support"
	@${ECHO} "	WITH_DEBUG		Builds with debugging arguments"
	@${ECHO} "	WITH_MYSQL		Builds with MySQL support"
	@${ECHO} ""
	@${ECHO} "	Note: the default database is BDB3"
	@${ECHO} ""

post-install:
	@ ${MKDIR} ${PREFIX}/share/bmf
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/bmf
	@ ${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
