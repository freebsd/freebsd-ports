# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	math cad parallel
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Scilab/distributions/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	js@jeannot.org
COMMENT=	A free Matlab clone by INRIA & ENPC

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		f77blas.1:${PORTSDIR}/math/atlas \
		lapack.3:${PORTSDIR}/math/lapack
BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS+=	${BUILD_DEPENDS}

PVM_ROOT=	${LOCALBASE}/lib/pvm

NO_CDROM=	"Don't sell for profit."

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--with-tk \
		--with-tk-library=${LOCALBASE}/lib \
		--with-tk-include=${LOCALBASE}/include/tk8.4 \
		--with-tcl-library=${LOCALBASE}/lib \
		--with-tcl-include=${LOCALBASE}/include/tcl8.4 \
		--with-pvm-library=${LOCALBASE}/lib \
		--with-pvm-include=${LOCALBASE}/include \
		--with-xaw3d \
		--x-include=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--with-atlas-library=${LOCALBASE}/lib

CONFIGURE_ENV=	PVM_ROOT=${PVM_ROOT} X11BASE=${X11BASE}
MAKE_ENV=	PVM_INCLUDE=${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102 || ${ARCH} == "sparc64"
BROKEN=		"Does not compile on alpha 5.x or sparc64"
.endif

post-patch:
	# malloc.h -> stdlib.h conversions
	${GREP} -lr "<malloc.h>" ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's/[<"]malloc.h[>"]/<stdlib.h>/'

pre-install:
	${FIND} ${WRKSRC} -name \*.orig -delete
	${FIND} ${WRKSRC} -name \*.bak -delete

.include <bsd.port.post.mk>
