# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

# NOTE TO VISITING COMMITTER: if you need to bump the port revisions
# of the slave ports, you should add PORTREVISION?= to the "master
# port" section below.

PORTNAME?=	bluecurve-themes
CATEGORIES=	x11-themes

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Meta-port for Bluecurve themes

NO_STAGE=	yes
.if ${PORTNAME} == "bluecurve-themes"	# meta-port

PORTVERSION=	1.0
# PORTREVISION is useless for a meta-port, but it was incorrectly
# added to the global section by someone (with the intent of bumping
# the revisions of the slave ports) and it cannot be removed without
# causing a version downgrade or using PORTEPOCH.
PORTREVISION=	8
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

# note: gtk-/icon-/metacity- are brought in by gnome-
RUN_DEPENDS=	${LOCALBASE}/lib/X11/icons/Bluecurve/cursors/X_cursor:${PORTSDIR}/x11-themes/cursor-bluecurve-theme \
		${LOCALBASE}/share/themes/Bluecurve/index.theme:${PORTSDIR}/x11-themes/gnome-bluecurve-theme

NO_BUILD=	yes

do-install:	# empty

.else					# master port

PORTVERSION=	7.0.0
PORTREVISION?=	4
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	../releases/7/Fedora/source/SRPMS/
DISTFILES=	redhat-artwork-${PORTVERSION}-9.fc7.src.rpm

USES+=		pkgconfig

WRKSRC=		${WRKDIR}/redhat-artwork-${PORTVERSION}

# the slave ports use their own pkg files and dirs
DESCR?=		${.CURDIR}/pkg-descr
PLIST?=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files
SCRIPTDIR=	${.CURDIR}/scripts

do-extract:
	@${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && ${TAR} -O -xf ${_DISTDIR}/${_DISTFILES} redhat-artwork-${PORTVERSION}.tar.gz | ${TAR} -xf -

.if defined(BC_HIERS)
.if !exists(${PLIST})
PLIST=		${WRKDIR}/pkg-plist

pre-install: bc-generate-plist
.endif

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
