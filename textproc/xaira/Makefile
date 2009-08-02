# New ports collection makefile for:	xaira
# Date created:		10 September 2007
# Whom:			Mathias Monnerville <mathias@monnerville.com>
#
# $FreeBSD$
#

PORTNAME=	xaira
PORTVERSION=	1.23
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	mathias@monnerville.com
COMMENT=	XML Aware Indexing and Retrieval Architecture

LIB_DEPENDS=	xerces-c:${PORTSDIR}/textproc/xerces-c2 \
		icuio:${PORTSDIR}/devel/icu

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:19 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal -I .
USE_GMAKE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	xaira-server
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	PHP5 "Build PHP5 extension" no

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.if defined(WITH_PHP5)
BUILD_DEPENDS+=	php5>=5:${PORTSDIR}/lang/php5
CONFIGURE_ARGS+=	--with-php5=`${LOCALBASE}/bin/php-config --include-dir`
PLIST_FILES+=	lib/libphpXaira.a \
	lib/libphpXaira.la \
	lib/libphpXaira.so \
	lib/libphpXaira.so.0
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am -exec \
		${REINPLACE_CMD} -e 's,^AM_CPPFLAGS.*$$,& $${icu_cppflags},' {} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
