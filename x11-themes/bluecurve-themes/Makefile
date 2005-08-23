# New ports collection makefile for:	bluecurve-themes
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	bluecurve-themes
CATEGORIES=	x11-themes

MAINTAINER=	jylefort@FreeBSD.org
COMMENT?=	Meta-port for Bluecurve themes

.if ${PORTNAME} == "bluecurve-themes"	# meta-port

PORTVERSION=	1.0
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

# note: gtk-/icon-/metacity- are brought in by gnome-
RUN_DEPENDS=	${X11BASE}/lib/X11/icons/Bluecurve/cursors/X_cursor:${PORTSDIR}/x11-themes/cursor-bluecurve-theme \
		${X11BASE}/share/themes/Bluecurve/index.theme:${PORTSDIR}/x11-themes/gnome-bluecurve-theme \
		${LINUXBASE}/usr/share/themes/Bluecurve/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/linux-gtk-bluecurve-theme \
		${X11BASE}/lib/plugins/styles/bluecurve.so:${PORTSDIR}/x11-themes/qt-bluecurve-theme \
		${X11BASE}/share/xmms/Skins/Bluecurve-xmms.zip:${PORTSDIR}/x11-themes/xmms-bluecurve-theme

NO_BUILD=	yes

do-install:	# empty

.else					# master port

PORTVERSION=	0.126
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	development/SRPMS
DISTFILES=	redhat-artwork-${PORTVERSION}-1.src.rpm

EXTRACT_DEPENDS+=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

WRKSRC=		${WRKDIR}/redhat-artwork-${PORTVERSION}
PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB

# the slave ports use their own pkg files and dirs
DESCR?=		${.CURDIR}/pkg-descr
PLIST?=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
	rpm2cpio.pl ${_DISTDIR}/${DISTFILES} | ${CPIO} -i --quiet redhat-artwork-${PORTVERSION}.tar.gz && \
	${TAR} -zxf redhat-artwork-${PORTVERSION}.tar.gz && \
	${RM} redhat-artwork-${PORTVERSION}.tar.gz

.if defined(BC_HIERS)

PLIST=		${WRKDIR}/pkg-plist

pre-install: bc-generate-plist

bc-generate-plist:
	@${RM} -f ${PLIST}
	@for h in ${BC_HIERS}; do \
		src=`${ECHO_CMD} "$$h" | ${CUT} -f 1 -d ':'` && \
		dst_rel=`${ECHO_CMD} "$$h" | ${CUT} -f 2 -d ':' | ${SED} -e 's|^${PREFIX}/||'` && \
		cd "$$src" && \
		${FIND} * ! -type d | ${SORT} \
			| ${SED} -e "s|^|$$dst_rel/|" >> ${PLIST} && \
		${FIND} * -type d ! -empty | ${SORT} -r \
			| ${SED} -e "s|^|@dirrm $$dst_rel/|" >> ${PLIST}; \
	done

do-install:
	for h in ${BC_HIERS}; do \
		src=`${ECHO_CMD} "$$h" | ${CUT} -f 1 -d ':'` && \
		dst=`${ECHO_CMD} "$$h" | ${CUT} -f 2 -d ':'` && \
		${MKDIR} "$$dst" && cd "$$src" && \
		${FIND} * -type d ! -empty -exec \
			${MKDIR} "$$dst/{}" \; && \
		${FIND} * -type l -exec \
			${CP} -Rf "{}" "$$dst/{}" \; && \
		${FIND} * ! -type d ! -type l -exec \
			${INSTALL_DATA} "{}" "$$dst/{}" \; ; \
	done

.endif				# BC_HIERS

.endif				# master port

.if !defined(_BC_MK_INCLUDED)
.include <bsd.port.mk>
.endif
