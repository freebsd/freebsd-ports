# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hdup
PORTVERSION=	2.0.14
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.miek.nl/projects/hdup2/ \
		http://www.miek.nl/projects/hdup2/previous/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	The little, spiffy, backup tool

#WRKSRC=		${WRKDIR}/hdup2

OPTIONS_DEFINE=	GNUTAR_PORT DOCS
GNUTAR_PORT_DESC=	GNU tar from ports

BUILD_DEPENDS=	mcrypt:${PORTSDIR}/security/mcrypt
RUN_DEPENDS=	mcrypt:${PORTSDIR}/security/mcrypt \
		gpgv:${PORTSDIR}/security/gnupg1 \
		lzop:${PORTSDIR}/archivers/lzop

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	autoconf

MAN1=		hdup.1
MAN5=		hdup.conf.5

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTAR_PORT}
BUILD_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
GNUTAR=		${LOCALBASE}/bin/gtar
.else
# bsdtar appeared
GNUTAR=		/usr/bin/gtar
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#%%GNUTAR%%#${GNUTAR}#g' ${WRKSRC}/src/hdup.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${DOCSDIR}; \
	${MKDIR} ${EXAMPLESDIR}; \
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
