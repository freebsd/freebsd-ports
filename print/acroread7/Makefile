# New ports collection makefile for:	acroread7
# Date created:		16 March 2005
# Whom:			Trevor Johnson <trevor@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread7
PORTVERSION=	7.0.0
CATEGORIES=	print linux
MASTER_SITES=	http://download.adobe.com/pub/adobe/reader/unix/7x/7.0/enu/ \
		ftp://ftp.adobe.com/pub/adobe/reader/unix/7x/7.0/enu/
DISTNAME=	AdobeReader_enu-7.0.0-2.i386.rpm
EXTRACT_SUFX=
DIST_SUBDIR=	acroread
EXTRACT_ONLY=
RESTRICTED=	"Must fill out redistribution form at http://www.adobe.com/products/acrobat/distribute.html"

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	View, distribute and print PDF documents

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango \
		${LINUXBASE}/usr/X11R6/lib/libXext.so.6:${PORTSDIR}/x11/linux-XFree86-libs

CONFLICTS=	acroread

ONLY_FOR_ARCHS=	amd64 i386
USE_REINPLACE=	yes
USE_LINUX?=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i '' -E
NO_FILTER_SHLIBS=	yes
PLIST=		${WRKDIR}/plist
PREFIX=		${LINUXBASE}

pre-install:
	@kldstat -v | ${GREP} -E 'linux(aout|elf)' >/dev/null ||\
		{ ${ECHO_MSG} "Linux ABI compatibility must be enabled to install ${PORTNAME}-${PORTVERSION}"; \
		  exit 1; }
	@${RM} -rf ${WRKSRC}/tmp
	@${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} | ${CPIO} -id; \
		${RM} -rf usr/bin/acroread; \
		${FIND} * -type f -o -type l > ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' | \
		${GREP} -vE "(usr/bin$$|local$$|share$$|usr$$)" >> ${PLIST}
	@${ECHO} @cwd %%LOCALBASE%% >> ${PLIST}
	@${ECHO} bin/acroread7 >> ${PLIST}
	@${ECHO} bin/acroread >> ${PLIST}

do-install:
	@rpm -U --ignorearch --ignoreos --root ${PREFIX} --dbpath /var/lib/rpm \
		 --nodeps --replacepkgs ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} || ${TRUE}
	# disable the PPKLite plugin as it requires an LDAP share lib
	${CHMOD} 0 ${PREFIX}/usr/local/Adobe/Acrobat7.0/Reader/intellinux/plug_ins/PPKLite.api

post-install:
	@${REINPLACE_CMD} 's:Linux:FreeBSD|Linux:g' \
		${PREFIX}/usr/local/Adobe/Acrobat7.0/bin/acroread
	cd ${LOCALBASE}/bin ; ${LN} -sf ${PREFIX}/usr/local/Adobe/Acrobat7.0/bin/acroread acroread7
	cd ${LOCALBASE}/bin ; ${LN} -sf ${PREFIX}/usr/local/Adobe/Acrobat7.0/bin/acroread acroread
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/usr/local/Adobe/Acrobat7.0/Reader/Legal/ENU/license_ENU_uc.txt"

.include <bsd.port.mk>
