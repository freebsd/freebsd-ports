# New ports collection makefile for:	linux-beonex
# Date created:				2002-10-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	beonex
PORTVERSION=	0.8.1
CATEGORIES=	www linux
MASTER_SITES=	\
http://ftp.ibiblio.org/pub/packages/infosystems/WWW/clients/beonex/communicator/0.8/\
ftp://ftp.ibiblio.org/pub/packages/infosystems/WWW/clients/beonex/communicator/0.8/
PKGNAMEPREFIX=	linux-
DISTNAME=	beonex-comm-${PORTVERSION}-stable-1-linux-i686

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=trevor

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	\
	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes
ONLY_FOR_ARCHS=	i386
PATCH_FILES=	linux-beonex-generated-files-${PORTVERSION}.tar.bz2
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_BZIP2=	yes
USE_LINUX=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/beonex-comm

post-extract:
	${RM}	${WRKSRC}/chrome/chatzilla.jar \
		${WRKSRC}/components/chatzilla-service.js

do-patch:
	${BZIP2_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${PATCH_FILES} | \
		${TAR} -C ${WRKSRC} -xf -
	${ECHO_CMD} "#!/bin/sh"			>${WRKDIR}/linkfarm
	${ECHO_CMD} "# Run this after installing Mozilla or Netscape plugins." \
		>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/linux-beonex/plugins" \
		>>${WRKDIR}/linkfarm
.for ii in netscape-linux/plugins flash linux-mozilla/plugins \
	linux-netscape*/plugins
		${ECHO_CMD} -n "${FIND} ${LOCALBASE}/lib/${ii}/*" \
			>>${WRKDIR}/linkfarm
		${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null" \
			>>${WRKDIR}/linkfarm
.endfor

pre-install:
	${ECHO_CMD} bin/linux-beonex > ${PLIST}
	${ECHO_CMD} "@unexec ${FIND} ${PREFIX}/lib/linux-beonex/plugins -type l\
		-exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/linux-beonex/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/linux-beonex/:' >> ${PLIST}
	${ECHO_CMD} lib/linux-beonex/linkfarm >> ${PLIST}
	${ECHO_CMD} @dirrm lib/linux-beonex >> ${PLIST}
	${ECHO_CMD} "@exec ${PREFIX}/lib/linux-beonex/linkfarm" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/linux-beonex
	${CHMOD} 755 ${PREFIX}/lib/linux-beonex
	cd ${WRKSRC} && ${FIND} * | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/linux-beonex
	${LN} -s ${PREFIX}/lib/linux-beonex/beonex-comm \
		${PREFIX}/bin/linux-beonex
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${PREFIX}/lib/linux-beonex

post-install:
	@${ECHO_CMD} \
		\*\* After adding plugins to \(Linux\) Mozilla or Netscape, run\
		> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* ${PREFIX}/lib/linux-beonex/linkfarm >> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* as root to make them available to linux-beonex. \
		>> ${PKGMESSAGE}
	@- ${SH} ${PREFIX}/lib/linux-beonex/linkfarm || true
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
