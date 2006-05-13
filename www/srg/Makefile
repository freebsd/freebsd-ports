# New ports collection makefile for:	srg
# Date created:		28 June 2004
# Whom:			Dmitry Semkin <lslarry@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	srg
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://mirror.crc.net.nz/pub/srg/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ds@tic-tac.ru
COMMENT=	A Squid Report Generator

USE_GMAKE=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_GETOPT_LONG=yes
NO_INSTALL_MANPAGES=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} -e 's|-g |${CFLAGS} ${CPPFLAGS} |' ${WRKSRC}/Makefile \
		${WRKSRC}/lib/Makefile
	${REINPLACE_CMD} -e 's|^\(LDFLAGS\)=|\1+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/srg ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
