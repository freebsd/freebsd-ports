# -*-mode: makefile-*-
# New ports collection makefile for:	kdenetwork2
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	${KDE_VERSION}
CATEGORIES?=	net kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Network-related programs and modules for KDE

LIB_DEPENDS=	idn:${PORTSDIR}/devel/libidn \
		slp:${PORTSDIR}/net/openslp
RUN_DEPENDS=	nmblookup:${PORTSDIR}/net/samba3

CONFLICTS=	kopete-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_RC_SUBR=	YES
USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
_NO_KDE_CLOSURE=yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|g' \
		${WRKSRC}/kopete/protocols/gadu/libgadu/libgadu-config.h.in
.endif
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/lanbrowsing/kcmlisa/main.cpp \
		${WRKSRC}/lanbrowsing/kcmlisa/kcmlisa.cpp \
		${WRKSRC}/lanbrowsing/kcmlisa/setupwizard.cpp

post-configure:
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} -e 's|$$(depcomp)||g' \
		${WRKSRC}/kopete/protocols/jabber/libiris/iris/xmpp-core/Makefile
.endif

post-install:
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/lisa.sh > ${PREFIX}/etc/rc.d/lisa.sh
	${CHMOD} +x ${PREFIX}/etc/rc.d/lisa.sh

.include <bsd.port.post.mk>
