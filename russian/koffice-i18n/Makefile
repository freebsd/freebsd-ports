# New ports collection makefile for:	ru-koffice-i18n
# Date created:				22 December 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.1.1
CATEGORIES=	russian kde misc
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	koshell:${PORTSDIR}/editors/koffice

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-ru

.include <bsd.port.pre.mk>

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor

.include <bsd.port.post.mk>
