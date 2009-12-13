# ex:ts=8
# New ports collection makefile for:	cgi++
# Date created:			Mar 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgicc
PORTVERSION=	3.2.9
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ class library for writing CGI applications

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
USE_LDCONFIG=	yes

PORTDOCS=	*

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CXXFLAGS/s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in

post-build:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${ALL_TARGET})
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
