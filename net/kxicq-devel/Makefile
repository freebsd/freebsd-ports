# New ports collection makefile for:   kxicq-devel
# Date created:        22 June 2002
# Whom:                Lauri Watts et al. <kde-freebsd@lists.csociety.org>
#
# $FreeBSD$

PORTNAME=	kxicq2
PORTVERSION=	20020622
CATEGORIES=	net kde
MASTER_SITES=	http://krazykiwi.homeip.net/kxicq2/ \
		http://zappa.athame.co.uk/FreeBSD/projects/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-cvs-kde3-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

pre-configure:
	@(cd ${WRKSRC} && ${GMAKE} -f Makefile.cvs)

.include <bsd.port.mk>
