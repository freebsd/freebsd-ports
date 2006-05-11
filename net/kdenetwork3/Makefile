# -*-mode: makefile-*-
# New ports collection makefile for:	kdenetwork2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES?=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Network-related programs and modules for KDE

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn \
		slp:${PORTSDIR}/net/openslp
RUN_DEPENDS=	${QT_PREFIX}/lib/plugins/crypto/libqca-tls.so:${PORTSDIR}/security/qca-tls

CONFLICTS=	kopete-[0-9]* kvirc-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

USE_AUTOTOOLS=  libtool:15
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
DO_NOT_COMPILE+=lanbrowsing
_NO_KDE_FINAL=	yes

CONFIGURE_ARGS+=--with-ssl-dir=/

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} \
	-E -e '/^SUBDIRS/s/lisa//g' \
		${WRKSRC}/doc/Makefile.in

post-configure:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} -e 's|$$(depcomp)||g' \
		${WRKSRC}/kopete/protocols/jabber/libiris/iris/xmpp-core/Makefile
.endif

.include <bsd.port.post.mk>
