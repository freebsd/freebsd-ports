# New ports collection makefile for:   gtk20-apireference
# Date created:        13 June 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	gtk20-apireference
PORTVERSION=	20021211
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://developer.gnome.org/doc/API/
DISTFILES=	glib-2.0-docs.tar.gz gtk-2.0-docs.tar.gz gdk-2.0-docs.tar.gz

MAINTAINER=	edwin@mavetju.org

NO_BUILD=	yes
NO_CHECKSUM=	yes		# they're rebuild too often to keep track of
PLIST=		${WRKDIR}/plist
PREFIX=		${X11BASE}

post-extract:
	@${ECHO_MSG} "===> Creating pkg-plist."
	@cd ${WRKDIR}; \
	${RM} -f ${PLIST}; \
	${RM} -f ${PLIST}.tmp; \
	for dir in gdk glib gtk; do \
	    find $${dir} -type f >> ${PLIST}.tmp ; \
	    ${ECHO} "@dirrm share/doc/$${dir}20" >> ${PLIST}.tmp; \
	done; \
	${SED}	-e 's/^gdk/share\/doc\/gdk20/' \
		-e 's/^gtk/share\/doc\/gtk20/' \
		-e 's/^glib/share\/doc\/glib20/' < ${PLIST}.tmp > ${PLIST}; \
	${RM} ${PLIST}.tmp

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gdk20
	@${MKDIR} ${PREFIX}/share/doc/gtk20
	@${MKDIR} ${PREFIX}/share/doc/glib20
	${CP} -R ${WRKDIR}/gdk/* ${PREFIX}/share/doc/gdk20
	${CP} -R ${WRKDIR}/glib/* ${PREFIX}/share/doc/glib20
	${CP} -R ${WRKDIR}/gtk/* ${PREFIX}/share/doc/gtk20

.include <bsd.port.mk>
