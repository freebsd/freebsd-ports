# New ports collection makefile for:	pike
# Date created:		11 Jul 2003
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	caudium-devel
PORTVERSION=	1.3.21.20031129
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.oav.net/caudium/source/ \
		ftp://ftp.caudium.net/caudium/source/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://grendel.firewall.com/caudium-pkg/ \
		ftp://ftp.oav.net/caudium/source/old/ \
		ftp://ftp.caudium.net/caudium/snapshot/1.3/
DISTNAME=	caudium-${PORTVERSION:S/.20/-20/}-cvs

MAINTAINER=	kiwi@oav.net
COMMENT=	A free webserver which is based on the Roxen Challenger 1.3 code base (development branch)

BUILD_DEPENDS=	pike:${PORTSDIR}/lang/pike74/
LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron/ \
		pcre.0:${PORTSDIR}/devel/pcre/ \
		mhash.2:${PORTSDIR}/security/mhash/
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof/

WRKSRC=		${WRKDIR}/${DISTNAME}

PIKEVERSION=	7.4.31

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --without-debug --with-PiXSL --prefix=${PREFIX} \
		 --with-pike=${PREFIX}/bin/pike

USE_GMAKE=	yes

PLIST_SUB+=	PIKEVERSION=${PIKEVERSION}

pre-configure:
	@${ECHO} ${CONFIGURE_ENV}
	@${ECHO} ${CONFIGURE_ARGS}

post-build:
	@${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/caudium.sh >${WRKDIR}/caudium.sh

post-install:
#	@${RM} ${PREFIX}/caudium/server/base_server/caudium.pike.orig
	@${CHOWN} -R www:www ${PREFIX}/caudium
	@${INSTALL_SCRIPT} ${WRKDIR}/caudium.sh ${PREFIX}/etc/rc.d/caudium.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
