# Ports collection makefile for:	mod_cplusplus for Apache 2.x
# Date created:		Dec 29, 2006
# Whom:			Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	mod_cplusplus
PORTVERSION=	1.5.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modcplusplus

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	Apache module for loading C++ objects as handlers

USE_APACHE=	2.0+
USE_AUTOTOOLS=	autoconf:259 autoheader:259 libtool:15 automake:19 aclocal:19
# ${LOCALBASE}/share/aclocal19 does not contain libtool.m4 and that causes
# problems.  Explicitly include ${LOCALBASE}/share/aclocal in the search
# patch since that directory does contain libtool.m4
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS+=	-a
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}

SUB_FILES=	pkg-message
SUB_LIST=	"APACHEMODDIR=${APACHEMODDIR}"

# Redefine the autotools run order to match what would happen in the
# autogen.sh script.  We cannot use that script directly since it does
# not use the versioned autotools.
run-autotools: run-autotools-aclocal patch-autotools run-autotools-autoheader \
    run-libtoolize run-autotools-automake run-autotools-autoconf

run-libtoolize:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} \
	    ${LIBTOOLIZE} --force --copy)

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/${APACHEINCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmod_cplusplus.so ${PREFIX}/${APACHEMODDIR}/mod_cplusplus.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
