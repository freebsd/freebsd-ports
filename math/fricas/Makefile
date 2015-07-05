# Created by: stephen@math.missouri.edu
# $FreeBSD$

PORTNAME=	fricas
PORTVERSION=	1.2.6
DISTVERSIONSUFFIX=	-full
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Computer algebra system, forked from axiom

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/LICENSE.AXIOM

BUILD_DEPENDS=	noweb:${PORTSDIR}/devel/noweb \
		sbcl:${PORTSDIR}/lang/sbcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	x11 ice sm xpm
USES=		gettext iconv gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=sbcl
USE_LDCONFIG=	${PREFIX}/lib/fricas/target/${CONFIGURE_TARGET}/lib

STRIP=		#nothing, these binaries fail if stripped

PLIST_SUB=	GNU_HOST="${CONFIGURE_TARGET}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/CCF=/s|-O2 -pipe|$$CFLAGS| ; \
		 /CCF=/s|/usr/local/include|${LOCALBASE}/include| ; \
		 /LDF=/s|/usr/local/lib|${LOCALBASE}/lib|' ${WRKSRC}/configure

.include <bsd.port.mk>
