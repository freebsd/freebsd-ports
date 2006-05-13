# New ports collection makefile for:   gtk20-apireference
# Date created:        13 June 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	gtk20-apireference
PORTVERSION=	20021211
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://developer.gnome.org/doc/API/
DISTFILES=	${MODULES:C/$/-2.0-docs${EXTRACT_SUFX}/}

MAINTAINER=	edwin@mavetju.org
COMMENT=	API reference for the Gimp Toolkit v2.x for X11 GUI

IGNOREFILES=	${DISTFILES}

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
PREFIX=		${X11BASE}	# do not use USE_X_PREFIX, does not depend on X
REINPLACE_ARGS=	-i ""		# do not save backups

MODULES=	glib gobject gdk gdk-pixbuf gtk

post-extract:
	@${ECHO_MSG} "===>  Creating pkg-plist"
	@${RM} -f ${PLIST}
.for dir in ${MODULES}
	@${MV} ${WRKDIR}/${dir}/${dir}.devhelp ${WRKDIR}/${dir}/${dir}20.devhelp
	@cd ${WRKDIR}; ${FIND} ${dir} -type f >> ${PLIST}
	@${ECHO} "@dirrm share/doc/${dir}20" >> ${PLIST}
	@${REINPLACE_CMD} -e 's|^${dir}|share/doc/${dir}20|' ${PLIST}
.endfor

post-patch:
.for dir in ${MODULES}
	@${FIND} ${WRKDIR}/${dir} -name '*.html' | ${XARGS} ${REINPLACE_CMD} -e \
		's|href="\.\./glib/|href="\.\./glib20/|g ; \
		 s|href="\.\./gobject/|href="\.\./gobject20/|g ; \
		 s|href="\.\./gdk/|href="\.\./gdk20/|g ; \
		 s|href="\.\./gdk-pixbuf/|href="\.\./gdk-pixbuf20/|g ; \
		 s|href="\.\./gtk/|href="\.\./gtk20/|g'
.endfor

do-install:
.for dir in ${MODULES}
	${MKDIR} ${PREFIX}/share/doc/${dir}20
	${CP} -R ${WRKDIR}/${dir}/* ${PREFIX}/share/doc/${dir}20
.endfor

.include <bsd.port.mk>
