# ex:ts=8
# Ports collection makefile for:	gss
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gss
PORTVERSION=	0.0.12
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/ \
		${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

LIB_DEPENDS=	shishi.0:${PORTSDIR}/security/shishi

USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GETOPT_LONG=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-kerberos5
INSTALLS_SHLIB=	yes

INFO=	gss

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.post.mk>
