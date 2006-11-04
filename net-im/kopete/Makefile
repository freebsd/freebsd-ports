# -*-mode: makefile-*-
# New ports collection makefile for:	kdenetwork2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kopete
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES?=	net-im kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/3.5.4/src
PKGNAMEPREFIX=	kdenetwork-
DISTNAME=	kdenetwork-3.5.4
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	KDE multi-protocol instant messenger (IM)

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn
RUN_DEPENDS=	${QT_PREFIX}/lib/plugins/crypto/libqca-tls.so:${PORTSDIR}/security/qca-tls

CONFLICTS=	kdenetwork-[0-2]* kdenetwork-3.[0-4]* kdenetwork-3.5.[0-2]* kvirc-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_OPENSSL=	yes

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
CONFIGURE_ARGS+=--with-ssl-dir=${OPENSSLBASE}

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/kopete
INSTALL_WRKSRC=	${WRKSRC}/kopete

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

post-configure:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} -e 's|$$(depcomp)||g' \
		${WRKSRC}/kopete/protocols/jabber/libiris/iris/xmpp-core/Makefile
.endif

.include <bsd.port.post.mk>
