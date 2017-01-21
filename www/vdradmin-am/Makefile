# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdradmin-am
PORTVERSION=	3.6.10
CATEGORIES=	www
MASTER_SITES=	http://andreas.vdr-developer.org/vdradmin-am/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - webinterface

BUILD_DEPENDS=	bash:shells/bash \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Template-Plugin-JavaScript>=0:www/p5-Template-Plugin-JavaScript \
		p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-IO-Compress>=0:archivers/p5-IO-Compress \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS=	p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Template-Plugin-JavaScript>=0:www/p5-Template-Plugin-JavaScript \
		p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-IO-Compress>=0:archivers/p5-IO-Compress \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-libwww>=0:www/p5-libwww

DIST_SUBDIR=	vdr
PATCH_STRIP=	-p1
USES=		shebangfix tar:bzip2
SHEBANG_FILES=	vdradmind.pl
WRKSRC=		${WRKDIR}/${PORTNAME:S/_/-/}-${DISTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes
USE_RC_SUBR=	vdradmind

VIDEODIR=	/video
LIBDIR=		${DATADIR}
MAKE_ENV+=	LIBDIR=${LIBDIR}
MAKE_ENV+=	ETCDIR=${ETCDIR}
MAKE_ENV+=	DOCDIR=${DOCSDIR}
MAKE_ENV+=	BINDIR=${PREFIX}/bin
MAKE_ENV+=	LOCDIR=${PREFIX}/share/locale
MAKE_ENV+=	MANDIR=${PREFIX}/man
MAKE_ENV+=	LOGDIR=/var/log/${PORTNAME}
MAKE_ENV+=	CACHEDIR=/var/cache/${PORTNAME}
MAKE_ENV+=	PIDFILE=/var/run/${PORTNAME}/vdradmind.pid
MAKE_ENV+=	VIDEODIR=${VIDEODIR}
MAKE_ENV+=	EPGIMAGES=${VIDEODIR}/epgimages
MAKE_ENV+=	VDRCONF=${PREFIX}/etc/vdr

VDR_USER=	vdr
VDR_GROUP=	vdr
USERS=		${VDR_USER}
GROUPS=		${VDR_GROUP}
PLIST_SUB=	VDR_USER=${VDR_USER}
PLIST_SUB+=	VDR_GROUP=${VDR_GROUP}
PLIST_SUB+=	PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 1s-^#!/bin/bash-#!${LOCALBASE}/bin/bash- \
		${WRKSRC}/install.sh ${WRKSRC}/make.sh

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/vdradmind.conf ${STAGEDIR}${ETCDIR}/vdradmind.conf.sample
	${MKDIR}  ${STAGEDIR}/var/cache/${PORTNAME} \
		${STAGEDIR}/var/log/${PORTNAME} ${STAGEDIR}/var/run/${PORTNAME}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} \
		./install.sh)

.include <bsd.port.mk>
