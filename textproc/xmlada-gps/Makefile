# New ports collection makefile for: xmlada-gps
# Date created:		31 Dec 2006
# Whom:			John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	xmlada-gps
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://libre.adacore.com/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	The Ada Unicode and XML Library

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

CONFLICTS=	xmlada-[0-9]*
BROKEN=		does not build

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
XMLADA_SRC=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

# Check for GNAT sources.
.if !exists(${DISTDIR}/${XMLADA_SRC}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=:\n\
Because of licensing and registration restrictions, you must fetch the\n\
source distribution manually.  Please access http://libre.adacore.com/\n\
with a web browser, register (it's free), and log in.  Download the source\n\
files:\n\
\t${XMLADA_SRC}\n\
and place them in ${DISTDIR}.\n
.endif

WRKSRC=		${WRKDIR}/xmlada-2.1
DOCSDIR=	${PREFIX}/share/doc/xmlada
MAKE_ENV=	"INSTALL_DATA=${INSTALL_DATA}" \
		"INSTALL_SCRIPT=${INSTALL_SCRIPT}"

# Weird permission problems creep up on install unless done explicitly
# this way.
do-install:
	@(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
# Manual install of info file since it lacks an entry field
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install_docs)
	@install-info --entry "XmlAda" ${DOCSDIR}/xml.info \
		${DOCSDIR}/dir
.endif

.include <bsd.port.post.mk>
