# New ports collection makefile for:	iiimf-server
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	server
PORTVERSION=	12.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet/Intranet Input Method Server Framework

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib

ONLY_FOR_ARCHS=	i386

USE_LDCONFIG=	yes
USE_RC_SUBR=	iiimd.sh
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig libxml2
USE_OPENSSL=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/iiimsf

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-g -ggdb -DDEBUG
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am
	${REINPLACE_CMD} -e "s,/usr/lib/iiim,${PREFIX}/lib/iiim,g" \
		${BUILDDIR}/src/le.xml.conf
	${MV} ${BUILDDIR}/iiimd.xml.conf ${BUILDDIR}/iiimd.xml.conf.sample
	${MV} ${BUILDDIR}/src/le.xml.conf ${BUILDDIR}/src/le.xml.conf.sample

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

post-install:
	${INSTALL_DATA} ${BUILDDIR}/src/le.xml.conf.sample ${PREFIX}/etc/iiim/

.include <bsd.port.post.mk>
