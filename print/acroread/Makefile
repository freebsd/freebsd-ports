# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	7.0.0
CATEGORIES=	print linux
MASTER_SITES=	http://download.adobe.com/pub/adobe/reader/unix/7x/7.0/enu/ \
		ftp://ftp.adobe.com/pub/adobe/reader/unix/7x/7.0/enu/
DISTNAME=	AdobeReader_enu-7.0.0-1.i386.rpm
EXTRACT_SUFX=
DIST_SUBDIR=	acroread
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	View, distribute and print PDF documents

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango

ONLY_FOR_ARCHS=	amd64 i386
USE_REINPLACE=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i '' -E
NO_FILTER_SHLIBS=	yes
PLIST=		${WRKDIR}/plist
PREFIX=		${LINUXBASE}

pre-install:
	@kldstat -v | grep -E 'linux(aout|elf)' >/dev/null ||\
		{ echo "Linux ABI compatibility must be enabled to install ${PORTNAME}-${PORTVERSION}"; \
		  exit 1; }
	@${RM} -rf ${WRKSRC}/tmp
	@${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} | ${CPIO} -id; \
		${FIND} * -type f -o -type l > ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' | \
		${GREP} -vE "(usr/bin$$|local$$|share$$|usr$$)" >> ${PLIST}

do-install:
	@rpm -U --ignorearch --ignoreos --root ${PREFIX} --dbpath /var/lib/rpm \
		 --nodeps --replacepkgs ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} || ${TRUE}

post-install:
	@${REINPLACE_CMD} 's:Linux:FreeBSD|Linux:g' \
		${PREFIX}/usr/local/Adobe/Acrobat7.0/bin/acroread
	cd ${LOCALBASE}/bin ; ${LN} -sf ${PREFIX}/usr/local/Adobe/Acrobat7.0/bin/acroread acroread7
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/usr/local/Adobe/Acrobat7.0/Reader/Legal/ENU/license_ENU_uc.txt"
	@${ECHO_MSG} "Use the acroread7 command to run this program."

.include <bsd.port.mk>
