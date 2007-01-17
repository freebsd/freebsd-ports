# New ports collection makefile for: xmlada-gps
# Date created:		31 Dec 2006
# Whom:			John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	xmlada-gps
PORTVERSION=	3.1.3
CATEGORIES=	textproc
MASTER_SITES=	http://libre.adacore.com/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	The Ada Unicode and XML Library

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat

CONFLICTS=	xmlada-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

# Check for GNAT sources.
.if !exists(${DISTDIR}/${DISTFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=	${PRINTF}
IGNORE=Because of licensing and registration restrictions, you must fetch\n \
	the source distribution manually.  Please access\n \
	http://libre.adacore.com/\ with a web browser, register\n \
	(It's free!) and log in.  Download the source files:\n\n \
	\t${DISTFILE}\n\n \
	and place them in ${DISTDIR}\n
	${ECHO_MSG} ${IGNORE}
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

.include <bsd.port.mk>
