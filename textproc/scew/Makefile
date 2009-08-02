# New ports collection makefile for:	scew
# Date created:        10 January 2008
# Whom:                Pietro Cerutti <gahr@gahr.ch>
#
# $FreeBSD$
#

PORTNAME=	scew
PORTVERSION=	0.4.0
CATEGORIES=	textproc
MASTER_SITES=	SAVANNAH/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple C Expat Wrapper

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
					LDFLAGS="-L${LOCALBASE}/lib"

SCEW_EXAMPLES=	print stream write

post-install:
.for ex in ${SCEW_EXAMPLES}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${PORTNAME}_${ex}/${PORTNAME}_${ex} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
