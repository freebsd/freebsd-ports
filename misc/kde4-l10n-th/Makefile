# New ports collection makefile for:	kde2-i18n
# Date created:				1 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	2.2.2
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

PLIST=		${WRKDIR}/PLIST
SCRIPTS_ENV+=	PLIST=${PLIST}

.include <bsd.port.pre.mk>

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
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/Configure

.include <bsd.port.post.mk>
