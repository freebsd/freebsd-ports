# New ports collection makefile for:	pike
# Date created:		05 Sep 2001
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	caudium10
PORTVERSION=	1.0.56
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.caudium.net/caudium/source/	\
		ftp://ftp.fr.caudium.net/pub/caudium/source/
DISTNAME=	caudium-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A free webserver which is based on the Roxen Challenger 1.3 code base

BUILD_DEPENDS=	pike:${PORTSDIR}/lang/pike70/
LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron/

WRKSRC=		${WRKDIR}/${DISTNAME}/

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug --with-PiXSL --prefix=${PREFIX}

USE_GMAKE=	yes
USE_BZIP2=	yes

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

post-configure:
	@cd ${WRKSRC}/src/cmods; \
	(for a in Caudium PiXSL UltraLog;do cd $$a; ${SED} s/"INSTALL=..\/"/"INSTALL=\/usr\/bin\/install -c"/ Makefile > Makefile.tmp; ${MV} -f Makefile.tmp Makefile; cd ..; done)
	@cd ${WRKSRC}/src/tools; ${SED} s/"INSTALL=..\/"/"INSTALL=\/usr\/bin\/install -c"/ Makefile > Makefile.tmp; ${MV} -f Makefile.tmp Makefile
	@cd ${WRKSRC}/src/fast_cgi; ${SED} s/"INSTALL=..\/"/"INSTALL=\/usr\/bin\/install -c"/ Makefile > Makefile.tmp; ${MV} -f Makefile.tmp Makefile

post-build:
	@${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/caudium.sh >${WRKDIR}/caudium.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/caudium.sh ${PREFIX}/etc/rc.d/caudium.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
