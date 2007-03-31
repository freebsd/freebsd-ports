# ex:ts=8
# New ports collection makefile for:	libdvdcss
# Date created:		Jul 6, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvdcss
PORTVERSION=	1.2.9
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	josh@tcbug.org
COMMENT=	Portable abstraction library for DVD decryption

NO_CDROM=	CSS code may violate the DMCA

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.ifndef(WITH_DOXYGEN)
NOPORTDOCS=	yes
.endif

.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen

PORTDOCS=	*
.endif

pre-everything::
.if !defined(WITH_DOXYGEN)
	@${ECHO_MSG} '==> Define WITH_DOXYGEN to build API documentation'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/ioctl.c
# should we disable doc building?
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]*SUBDIRS[[:space:]]*=.*)doc|\1|' \
		${BUILD_WRKSRC}/Makefile.in
.else
# we do not want the latex documents... too many dependencies just
# to get in ps what we already have in html
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]*all:[[:space:]]*.*)stamp-latex|\1|' \
		${BUILD_WRKSRC}/doc/Makefile.in
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
