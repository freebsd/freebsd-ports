# ex:ts=8
# New ports collection makefile for:	cgi++
# Date created:			Mar 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgicc
PORTVERSION=	3.2.8
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ class library for writing CGI applications

USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I m4 --install
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes

PORTDOCS=	*

post-extract:
	@${FIND} ${WRKSRC} -type l -delete

post-patch:
	@${REINPLACE_CMD} -e '/CXXFLAGS/s|-pedantic||g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.am

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} ${ACLOCAL_ARGS} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} ${AUTOHEADER_ARGS} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE})

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
