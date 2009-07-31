# New ports collection makefile for:	pike
# Date created:		15 May 2004
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	caudium12
PORTVERSION=	1.2.34
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.caudium.net/caudium/source/ \
		ftp://ftp.oav.net/caudium/source/
DISTNAME=	caudium-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A free webserver which is based on the Roxen Challenger 1.3 code base

BUILD_DEPENDS=	pike:${PORTSDIR}/lang/pike72/ \
		pexts>0:${PORTSDIR}/lang/pexts/
LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron/
RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof/ \
		pexts>0:${PORTSDIR}/lang/pexts/

WRKSRC=		${WRKDIR}/${DISTNAME}

PIKEVERSION=	7.2.570

# bash:${PORTSDIR}/shells/bash2/
#SH=		${PREFIX}/bin/bash
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug --with-PiXSL --prefix=${PREFIX} \
		 --with-pike=${LOCALBASE}/pike/${PIKEVERSION}/bin/pike

USE_GMAKE=	yes

PLIST_SUB+=	PIKEVERSION=${PIKEVERSION}

pre-configure:
	@${ECHO} ${CONFIGURE_ENV}
	@${ECHO} ${CONFIGURE_ARGS}

post-configure:
	@cd ${WRKSRC}/src/cmods; \
	(for a in Caudium PiXSL UltraLog;do cd $$a; ${SED} s/"INSTALL=..\/"/"INSTALL=\/usr\/bin\/install -c"/ Makefile > Makefile.tmp; ${MV} -f Makefile.tmp Makefile; cd ..; done)
	@cd ${WRKSRC}/src/tools; ${SED} s/"INSTALL=..\/"/"INSTALL=\/usr\/bin\/install -c"/ Makefile > Makefile.tmp; ${MV} -f Makefile.tmp Makefile
	@cd ${WRKSRC}/src/fast_cgi; ${SED} s/"INSTALL=..\/"/"INSTALL=\/usr\/bin\/install -c"/ Makefile > Makefile.tmp; ${MV} -f Makefile.tmp Makefile

post-build:
	@${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/caudium.sh >${WRKDIR}/caudium.sh

post-install:
#	@${RM} ${PREFIX}/caudium/server/base_server/caudium.pike.orig
	@${CHOWN} -R www:www ${PREFIX}/caudium
	@${INSTALL_SCRIPT} ${WRKDIR}/caudium.sh ${PREFIX}/etc/rc.d/caudium.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# is this really only true for sparc64?
.if ${ARCH} == sparc64
BROKEN=		does not install due to dependency error
.endif

.include <bsd.port.post.mk>
