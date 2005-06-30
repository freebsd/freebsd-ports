# New ports collection makefile for:	gatekeeper
# Date created:		Wed Apr 15 15:41:00 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gatekeeper
PORTVERSION=	2.2.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openh323gk
DISTNAME=	gnugk-${PORTVERSION}

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	GnuGK is GPL Gate Keeper for OhPhone, GnomeMeeting, NetMeeting and H323

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

USE_RC_SUBR=	yes
RC_DIR=		${PREFIX}/etc/rc.d

USE_AUTOCONF_VER=	259
CONFIGURE_ENV=	${MAKE_ENV}

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	optnoshared addpasswd
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX} HAS_RADACCT=1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=	--enable-radius
.else
CONFIGURE_ARGS+=	--disable-radius
.endif

#.if defined(WITH_MYSQL)
#USE_MYSQL=	41
#CONFIGURE_ARGS+=	--enable-mysql \
#			--with-mysql-dir=${LOCALBASE}
#.else
CONFIGURE_ARGS+=	--disable-mysql
#.endif

#.if defined(WITH_PGSQL)
#USE_PGSQL=	yes
#CONFIGURE_ARGS+=	--enable-pgsql \
#			--with-pgsql-dir=${LOCALBASE}
#.else
CONFIGURE_ARGS+=	--disable-pgsql
#.endif

pre-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
	    ${FILESDIR}/gnugk.sh.sample > ${WRKDIR}/gnugk.sh

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/gnugk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/addpasswd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/complete.ini ${PREFIX}/etc/gnugk.ini.default
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKSRC}/etc/*.ini ${EXAMPLESDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gnugk.sh ${RC_DIR}
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
