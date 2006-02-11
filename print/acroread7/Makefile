# New ports collection makefile for:	acroread7
# Date created:		16 March 2005
# Whom:			Trevor Johnson <trevor@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread7
PORTVERSION=	7.0.1
CATEGORIES?=	print linux
MASTER_SITES=	\
	http://download.adobe.com/pub/adobe/reader/unix/7x/7.0/${ADOBE_LANG}/ \
	ftp://ftp.adobe.com/pub/adobe/reader/unix/7x/7.0/${ADOBE_LANG}/
DISTNAME=	AdobeReader_${ADOBE_LANG}-7.0.1-1.i386.rpm
EXTRACT_SUFX=
DIST_SUBDIR=	acroread
EXTRACT_ONLY=

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	View, search and print PDF documents

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango

RESTRICTED=	"Must fill out redistribution form at http://www.adobe.com/products/acrobat/distribute.html"
ADOBE_LANG?=	enu
INSTDIR=	lib/${PKGNAMEPREFIX}acroread
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	amd64 i386
PLIST=		${WRKDIR}/plist
SUB_FILES=	acroread7
SUB_LIST+=	INSTDIR=${INSTDIR}

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=          i386
RPMFLAGS+=     --ignorearch
.endif

do-build:
	@kldstat -v | ${GREP} -E 'linux(aout|elf)' >/dev/null ||\
		{ ${ECHO_MSG} "Linux ABI compatibility must be enabled to install ${PORTNAME}-${PORTVERSION}"; \
		  exit 1; }
	@${RM} -rf ${WRKSRC}
	${MKDIR} ${WRKSRC}/${INSTDIR}
	@${ECHO} bin/acroread7${CMD_SUFFIX} > ${PLIST}
	cd ${WRKSRC}/${INSTDIR}; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} | ${CPIO} -id
	cd ${WRKSRC}; \
		${FIND} ${INSTDIR} -type l -o -type f >> ${PLIST}; \
		${FIND} -d ${INSTDIR} -type d \
		| ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${FIND} ${INSTDIR} | ${CPIO} -dlmp ${LOCALBASE}
	@${FIND} ${LOCALBASE}/${INSTDIR} -type d -exec ${CHMOD} 755 \{\} \;
	@${INSTALL_SCRIPT} ${WRKDIR}/acroread7 \
		${PREFIX}/bin/acroread7${CMD_SUFFIX}
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/${INSTDIR}/usr/local/Adobe/Acrobat7.0/Reader/Legal/${ADOBE_LANG:U}/license_${ADOBE_LANG:U}_uc.txt"
	# disable the PPKLite plugin as it requires an LDAP share lib
	${CHMOD} 0 ${PREFIX}/${INSTDIR}/usr/local/Adobe/Acrobat7.0/Reader/intellinux/plug_ins/PPKLite.api

.include <bsd.port.post.mk>
