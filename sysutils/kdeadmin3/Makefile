# New ports collection makefile for:	kdeadmin
# Date created:				5 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeadmin
PORTVERSION=	2.2.2
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.include "${.CURDIR}/../../x11/kde2/Makefile.kde"

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	${PERL} -pi -e "s@DO_NOT_COMPILE qt@DO_NOT_COMPILE kuser qt@g" ${WRKSRC}/configure
	find ${WRKSRC}/kpackage -name "*.cpp" -or -name "*.c" -or -name "*.h" \
		| xargs ${PERL} -pi -e "s#typedef __off64_t off64_t;##g"

.include <bsd.port.mk>
