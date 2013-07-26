# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	xaira
PORTVERSION=	1.23
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mathias@monnerville.com
COMMENT=	XML Aware Indexing and Retrieval Architecture

LIB_DEPENDS=	xerces-c:${PORTSDIR}/textproc/xerces-c2 \
		icuio:${PORTSDIR}/devel/icu

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27
BROKEN=		leaves files behind on deinstallation

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoconf libtool
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal -I .
USE_GMAKE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	xaira-server
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	PHP5
PHP5_DESC=	Build PHP5 extension
OPTIONS_DEFAULT=	PHP5

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.if ${PORT_OPTIONS:MPHP5}
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
