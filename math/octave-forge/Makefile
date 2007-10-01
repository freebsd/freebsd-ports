# New ports collection makefile for:	octave-forge
# Date created:		5 May 2004
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	octave-forge
PORTVERSION=	2006.03.17
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	octave

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Many additional features to math/octave

BUILD_DEPENDS+=	qhull:${PORTSDIR}/math/qhull \
		octave:${PORTSDIR}/math/octave \
		gcsplit:${PORTSDIR}/sysutils/coreutils \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave \
		qhull:${PORTSDIR}/math/qhull \
		bash:${PORTSDIR}/shells/bash

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	# empty
CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX} \
		--x-libraries=${X11BASE}/lib \
		--x-includes=${X11BASE}/include

USE_FORTRAN=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION="`${LOCALBASE}/bin/octave-config -v`" GNU_HOST=${GNU_HOST}

MAN1=		mex.1

post-configure:
	 @${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/main/sparse/buildtests.sh
	 @${REINPLACE_CMD} -e 's+#! /bin/sh+#! ${LOCALBASE}/bin/bash+g;' ${WRKSRC}/octinst.sh

.include <bsd.port.post.mk>
