# New ports collection makefile for:	hdup
# Date created:				6 March 2005
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hdup
PORTVERSION=	2.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.miek.nl/projects/hdup2/ \
		http://www.miek.nl/projects/hdup2/previous

MAINTAINER=	sem@FreeBSD.org
COMMENT=	The little, spiffy, backup tool

WRKSRC=		${WRKDIR}/hdup2

OPTIONS=	GNUTAR_PORT "Build with the newest GNU tar from ports" no

BUILD_DEPENDS=	mcrypt:${PORTSDIR}/security/mcrypt
RUN_DEPENDS=	mcrypt:${PORTSDIR}/security/mcrypt \
		gpg:${PORTSDIR}/security/gnupg \
		lzop:${PORTSDIR}/archivers/lzop

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOCONF_VER=	259

MAN1=		hdup.1
MAN5=		hdup.conf.5

.include <bsd.port.pre.mk>

.if defined(WITH_GNUTAR_PORT)
BUILD_DEPENDS+=	${LOCALBASE}/gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS+=	${LOCALBASE}/gtar:${PORTSDIR}/archivers/gtar
GNUTAR=		${LOCALBASE}/bin/gtar
.elif ${OSVERSION} < 502110
GNUTAR=		/usr/bin/tar
.else
# bsdtar appeared
GNUTAR=		/usr/bin/gtar
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#%%GNUTAR%%#${GNUTAR}#g' ${WRKSRC}/src/hdup.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${DOCSDIR}; \
	${MKDIR} ${EXAMPLESDIR}; \
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
