# New ports collection makefile for: gtkada-gps
# Date created:		31 Dec 2006
# Whom:			John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	gtkada-gps
PORTVERSION=	3.1.3
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://libre.adacore.com/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	GNOME Gtk2 Ada Binding

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

CONFLICTS=	gtkada-[0-9]* gtkada-devel-[0-9]* gtkada-gcc-[0-9]*

USE_GNOME=	gtk20 libglade2
USE_GMAKE=	yes
GTKADA_SRC=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

# Check for GNAT sources.
.if !exists(${DISTDIR}/${GTKADA_SRC}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=:\n\
Because of licensing and registration restrictions, you must fetch the\n\
source distribution manually.  Please access http://libre.adacore.com/\n\
with a web browser, register (it's free), and log in.  Download the source\n\
files:\n\
\t${GTKADA_SRC}\n\
and place them in ${DISTDIR}.\n
.endif

WRKSRC=		${WRKDIR}/GtkAda-2.4.2
DOCSDIR=	${PREFIX}/share/doc/gtkada
EXAMPLESDIR=	${PREFIX}/share/examples/gtkada
MAKE_ENV=	"MAKE=${GMAKE}"

# This explicit call avoids some permission problems that seem insolveable
# any other way
do-install:
	@(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} \
		${MAKE_ARGS} install)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} \
		${MAKE_ARGS} install-doc)
.endif

.include <bsd.port.post.mk>
