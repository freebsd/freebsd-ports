# New ports collection makefile for:	gnomehier
# Date created:				2 July 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomehier
PORTVERSION=	1.0
PORTREVISION=	19
CATEGORIES=	misc gnome
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A utility port that creates the GNOME directory tree

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST?=		${WRKDIR}/pkg-plist

USE_X_PREFIX=	yes

do-fetch:
	@${DO_NADA}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} -f ${PLIST}
	@${CAT} ${FILESDIR}/dirlist | ${SORT} | ${SED} -e \
		's|$$|/.keep_me|' >> ${PLIST}
	@${ECHO_CMD} "etc/gconf/gconf.xml.defaults/schemas/apps/%gconf.xml" \
		>> ${PLIST}
	@${ECHO_CMD} "etc/gconf/gconf.xml.defaults/apps/%gconf.xml" \
		>> ${PLIST}
	@${CAT} ${FILESDIR}/dirlist | ${SORT} -r | ${SED} -e \
		's|^|@dirrm |' >> ${PLIST}

do-install:
	@for dir in `${CAT} ${FILESDIR}/dirlist`; \
	do \
		${MKDIR} ${PREFIX}/$${dir}; \
		${TOUCH} ${PREFIX}/$${dir}/.keep_me; \
	done
	${TOUCH} -f ${PREFIX}/etc/gconf/gconf.xml.defaults/schemas/apps/%gconf.xml
	${TOUCH} -f ${PREFIX}/etc/gconf/gconf.xml.defaults/apps/%gconf.xml

.include <bsd.port.mk>
