# New ports collection makefile for:	libxslt
# Date created:				9th February 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxslt
PORTVERSION=	1.1.14
CATEGORIES?=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	The XSLT C library for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_GNOME?=	gnomehack gnometarget libxml2
USE_REINPLACE=	yes
CONFIGURE_ARGS?= --with-html-dir=${PREFIX}/share/doc \
		--without-python
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(MASTERDIR)
_SLAVE_PORT=	yes
.else
MAN3=		libexslt.3 libxslt.3
MAN1=		xsltproc.1

OPTIONS=	MEM_DEBUG "Enable memory debugging" off
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if !defined(_SLAVE_PORT)
.if exists(${LOCALBASE}/lib/libgcrypt.so)
WITH_GCRYPT=	yes
.endif

.if defined(WITH_GCRYPT)
LIB_DEPENDS+=	gcrypt.13:${PORTSDIR}/security/libgcrypt
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Libxslt has the following additional tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_GCRYPT=yes			Turns on libgcrypt support"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$](bindir)/xsltproc|../xsltproc/xsltproc|g ; \
		s|[$$](bindir)/xmllint|../xmllint/xmllint|g' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.post.mk>
