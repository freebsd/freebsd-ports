# New ports collection makefile for:	octave-forge
# Date created:		5 May 2004
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	octave-forge
PORTVERSION=	2004.11.16
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	octave

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Many additional features to math/octave

BUILD_DEPENDS=	${LOCALBASE}/bin/qhull:${PORTSDIR}/math/qhull \
		${LOCALBASE}/bin/octave:${PORTSDIR}/math/octave \
		${LOCALBASE}/bin/gcsplit:${PORTSDIR}/sysutils/coreutils
RUN_DEPENDS=	${LOCALBASE}/bin/octave:${PORTSDIR}/math/octave \
		${LOCALBASE}/bin/qhull:${PORTSDIR}/math/qhull

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	# empty
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501000
BROKEN=		"texinfo problem"
.endif

GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION="`${LOCALBASE}/bin/octave-config -v`" GNU_HOST=${GNU_HOST}

MAN1=		mex.1

post-configure:
	 @${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/main/sparse/buildtests.sh
	 @${REINPLACE_CMD} -e 's+#! /bin/sh+#! ${LOCALBASE}/bin/bash+g;' ${WRKSRC}/octinst.sh

.include <bsd.port.post.mk>
