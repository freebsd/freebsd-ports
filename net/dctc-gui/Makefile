# New ports collection makefile for:	GUI to Direct Connect Text Client
# Date created:				Thu Nov 22 00:34:48 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.66
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	http://unixpages.org/distfiles/ \
		http://ac2i.tzo.com/dctc/
PKGNAMESUFFIX=	-gui
DISTNAME=	dc_gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A GUI to DirectConnect (www.neo-modus.com) text client

BUILD_DEPENDS=	dctc:${PORTSDIR}/net/dctc
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnome=${X11BASE} \
		--with-gtk-prefix=${LOCALBASE} \
		--enable-manual-db-detect \
		--with-libiconv-prefix=${LOCALBASE}

ADDITIONAL_SRCS=	sig_chld.c
#
DOC_FILES= COPYING ChangeLog README TODO

post-extract:
.for file in ${ADDITIONAL_SRCS}
	@${CP} ${FILESDIR}/${file} ${WRKSRC}/src
.endfor

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${REINPLACE_CMD} -E -e \
		's|ldb-4.0|ldb4|; \
		s|<(db.h>)|<db4/\1|'
	@${REINPLACE_CMD} -E -e 's|(hublist)|dc_\1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E -e \
		's|(hublist)(.+argv)|dc_\1\2|' \
		${WRKSRC}/src/init_fnc.c
# XXX - revise at every port update
	@${REINPLACE_CMD} -e "s|%'|%|g" ${WRKSRC}/src/*.c
#	@${REINPLACE_CMD} -E -e \
#		's|%lf|%f|; \
#		s|(%\.[[:digit:]])lf|\1f|' \
#		${WRKSRC}/src/*.c
# clean up so as to not break installation
	@${FIND} ${WRKSRC} -type f \
		-name "*.bak" \
		| ${XARGS} -n 10 -x ${RM}
# add sigchld handler
.for file in ${ADDITIONAL_SRCS}
	@${REINPLACE_CMD} -E -e \
		's|^(dc_gui_SOURCES.+)$$|\1 ${file}|; \
		s|^(dc_gui_OBJECTS[^\\]+)(\\*)$$|\1 ${file:S/.c$/.o/} \2|' \
		${WRKSRC}/src/Makefile.in
.endfor
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-x -n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'

post-configure:
	@${ECHO_CMD} '#ifndef MSG_NOSIGNAL' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '# define MSG_NOSIGNAL 0' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#endif' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#include <sys/param.h>' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#ifndef SEMVMX' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define SEMVMX 32767' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#endif' >> ${WRKSRC}/config.h

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}${PKGNAMESUFFIX}
.endfor
.endif

.include <bsd.port.mk>
