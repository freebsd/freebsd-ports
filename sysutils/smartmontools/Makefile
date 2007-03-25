# New ports collection makefile for:   smartmontools
# Date created:        12 October 2003
# Whom:                Eduard Martinescu
#
# $FreeBSD$
#

PORTNAME=	smartmontools
PORTVERSION=	5.37
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	S.M.A.R.T. disk monitoring tools

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} --mandir=${PREFIX}/man --enable-sample
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

SUB_FILES=	pkg-message
USE_RC_SUBR=	smartd

MAN5=		smartd.conf.5
MAN8=		smartd.8 smartctl.8

OPTIONS=	CISS "Support ciss(4) -- requires kernel source tree" off

.include <bsd.port.pre.mk>

.if defined(WITH_CISS)
.	if !exists(/sys/dev/ciss/cissio.h)
IGNORE=		built WITH_CISS requires /sys/dev/ciss/cissio.h
.	endif
CFLAGS+=	-I/sys/dev/ciss -I${FILESDIR}
EXTRA_PATCHES=	${FILESDIR}/ciss-patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| install-initdDATA | |' ${WRKSRC}/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
