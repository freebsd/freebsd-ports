# New ports collection makefile for:	linux-mozillafirebird
# Date created:				2003-06-03
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mozillafirebird
PORTVERSION=	0.7
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	firebird/releases/${PORTVERSION}
PKGNAMEPREFIX=	linux-
DISTNAME=	MozillaFirebird-${PORTVERSION}-i686-pc-linux-gnu

MAINTAINER=	voisine@yahoo.com
COMMENT=	Web browser branched from Mozilla

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
WRKSRC=		${WRKDIR}/MozillaFirebird

do-patch:
	${ECHO_CMD} "#!/bin/sh"		> ${WRKDIR}/linkfarm
	${ECHO_CMD} \
	"# Run this after installing Beonex, Mozilla or Netscape plugins." \
		>>${WRKDIR}/linkfarm
	${ECHO_CMD} "cd ${PREFIX}/lib/linux-mozillafirebird/plugins" \
		>>${WRKDIR}/linkfarm
.for ii in lib/linux-beonex/plugins lib/netscape-linux/plugins lib/flash \
	lib/linux-mozilla/plugins lib/linux-netscape*/plugins \
	lib/linux-flashplugin6 \
linux-blackdown-jdk1.3.1/jre/plugin/i386/mozilla \
linux-blackdown-jdk1.4.1/jre/plugin/i386/mozilla
		${ECHO_CMD} -n "${FIND} ${LOCALBASE}/${ii}/*" \
			>>${WRKDIR}/linkfarm
		${ECHO_CMD} " -maxdepth 1 -exec ${LN} -s {} \; 2>/dev/null" \
			>>${WRKDIR}/linkfarm
.endfor

pre-install:
	${ECHO_CMD} bin/linux-mozillafirebird > ${PLIST}
	${ECHO_CMD} \
		"@unexec ${FIND} ${PREFIX}/lib/linux-mozillafirebird/plugins \
		-type l -exec ${RM} {} \;" >> ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/linux-mozillafirebird/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/linux-mozillafirebird/:' >> ${PLIST}
	${ECHO_CMD} lib/linux-mozillafirebird/linkfarm >> ${PLIST}
	${ECHO_CMD} @dirrm lib/linux-mozillafirebird >> ${PLIST}
	${ECHO_CMD} "@exec ${PREFIX}/lib/linux-mozillafirebird/linkfarm" \
		>> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/linux-mozillafirebird
	${CHMOD} 755 ${PREFIX}/lib/linux-mozillafirebird
	cd ${WRKSRC} && ${FIND} * | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/lib/linux-mozillafirebird
	${LN} -sf ${PREFIX}/lib/linux-mozillafirebird/MozillaFirebird \
		${PREFIX}/bin/linux-mozillafirebird
	${INSTALL_SCRIPT} ${WRKDIR}/linkfarm \
		${PREFIX}/lib/linux-mozillafirebird

NEW_LIBSTDCXX=	${LINUXBASE}/usr/lib/libstdc++-libc6.2-2.so.3
OLD_LIBSTDCXX=	libstdc++-libc6.1-1.so.2

post-install:
	if [ ! -f ${NEW_LIBSTDCXX} ]; then \
		${LN} -s ${OLD_LIBSTDCXX} ${NEW_LIBSTDCXX}; \
	fi
	${ECHO_CMD} "@exec if [ ! -f ${NEW_LIBSTDCXX} ]; then ${LN} -s ${OLD_LIBSTDCXX} ${NEW_LIBSTDCXX}; fi" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec if [ -L ${NEW_LIBSTDCXX} ]; then ${RM} -f ${NEW_LIBSTDCXX}; fi" >> ${TMPPLIST}
	@${ECHO_CMD} \*\* After adding plugins to \(Linux\) Beonex,
	@${ECHO_CMD} \*\* Mozilla or Netscape, run\
		> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* ${PREFIX}/lib/linux-mozillafirebird/linkfarm as root \
		>> ${PKGMESSAGE}
	@${ECHO_CMD} \*\* to make them available to linux-mozillafirebird. \
		>> ${PKGMESSAGE}
	@- ${SH} ${PREFIX}/lib/linux-mozillafirebird/linkfarm || true
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
