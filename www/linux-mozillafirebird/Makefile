# New ports collection makefile for:	linux-phoenix
# Date created:				2002-10-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	phoenix
PORTVERSION=	0.2
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	phoenix/releases/${PORTVERSION}
PKGNAMEPREFIX=	linux-
DISTNAME=	phoenix-${PORTVERSION}-i686-pc-linux-gnu

MAINTAINER=	voisine@bytemobile.com

RUN_DEPENDS=	\
	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes
ONLY_FOR_ARCHS=	i386
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_LINUX=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/phoenix

do-patch:
	${ECHO_CMD} "#!/bin/sh"		> ${WRKDIR}/linkfarm
	${ECHO_CMD} \
	"# Run this after installing Beonex, Mozilla or Netscape plugins." \
		>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/linux-phoenix/plugins" \
		>>${WRKDIR}/linkfarm
.for ii in linux-beonex/plugins netscape-linux/plugins flash \
	linux-mozilla/plugins linux-netscape*/plugins
		${ECHO_CMD} -n "${FIND} ${LOCALBASE}/lib/${ii}/*" \
			>>${WRKDIR}/linkfarm
		${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null" \
			>>${WRKDIR}/linkfarm
.endfor

pre-install:
	${ECHO_CMD} bin/linux-phoenix > ${PLIST}
	${ECHO_CMD} "@unexec ${FIND} ${PREFIX}/lib/linux-phoenix/plugins \
		-type l -exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/linux-phoenix/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/linux-phoenix/:' >> ${PLIST}
	${ECHO_CMD} lib/linux-phoenix/linkfarm >> ${PLIST}
	${ECHO_CMD} @dirrm lib/linux-phoenix >> ${PLIST}
	${ECHO_CMD} "@exec ${PREFIX}/lib/linux-phoenix/linkfarm" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/linux-phoenix
	${CHMOD} 755 ${PREFIX}/lib/linux-phoenix
	cd ${WRKSRC} && ${FIND} * | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/linux-phoenix
	${LN} -s ${PREFIX}/lib/linux-phoenix/phoenix \
		${PREFIX}/bin/linux-phoenix
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm ${PREFIX}/lib/linux-phoenix

post-install:
	@${ECHO_CMD} \*\* After adding plugins to \(Linux\) Beonex,
	@${ECHO_CMD} \*\* Mozilla or Netscape, run\
		> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* ${PREFIX}/lib/linux-beonex/linkfarm >> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* as root to make them available to linux-phoenix. \
		>> ${PKGMESSAGE}
	@- ${SH} ${PREFIX}/lib/linux-phoenix/linkfarm || true
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
