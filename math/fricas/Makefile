# Created by: stephen@math.missouri.edu
# $FreeBSD$

PORTNAME=	fricas
PORTVERSION=	1.1.8
DISTVERSIONSUFFIX=	-full
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	A computer algebra system, forked from axiom

LICENSE=	BSD

BUILD_DEPENDS=	noweb:${PORTSDIR}/devel/noweb \
		sbcl:${PORTSDIR}/lang/sbcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_XORG=	x11 ice sm xpm
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=sbcl
USE_LDCONFIG=	${PREFIX}/lib/fricas/target/${CONFIGURE_TARGET}/lib
MAKE_JOBS_SAFE=	yes

STRIP=		#nothing, these binaries fail if stripped

PLIST_SUB=	GNU_HOST="${CONFIGURE_TARGET}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/CCF=/s|-O2 -pipe|$$CFLAGS| ; \
		 /CCF=/s|/usr/local/include|${LOCALBASE}/include| ; \
		 /LDF=/s|/usr/local/lib|${LOCALBASE}/lib|' ${WRKSRC}/configure

.include <bsd.port.mk>
