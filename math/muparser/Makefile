# New ports collection makefile for:	muparser
# Date created:		2006-02-14
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	muparser
PORTVERSION=	1.25
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	Mathematical expressions parser library written in C++

RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes

WRKSRC=	${WRKDIR}/muParser

# taken from audio/taglib
post-patch:
	@${REINPLACE_CMD} -e "s#\$$(libdir)/pkgconfig#${LOCALBASE}/libdata/pkgconfig#g" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E 's,^(CXXFLAGS|LDFLAGS) = ,\1 ?= ,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 501103 )
USE_GCC=	3.3+
.endif

.include <bsd.port.post.mk>
