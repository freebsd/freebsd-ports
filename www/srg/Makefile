# New ports collection makefile for:	srg
# Date created:		28 June 2004
# Whom:			Dmitry Semkin <lslarry@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	srg
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://mirror.crc.net.nz/pub/srg/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lslarry@gmail.com
COMMENT=	A Squid Report Generator

USE_GMAKE=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=yes
NO_INSTALL_MANPAGES=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/srg
.for i in footer.php header.php ip2user.txt srg.conf
PLIST_FILES+=	share/examples/srg/${i}
.endfor
PLIST_DIRS=	share/examples/srg

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Fails self-tests on sparc64"
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-g |${CFLAGS} ${CPPFLAGS} |' ${WRKSRC}/Makefile \
		${WRKSRC}/lib/Makefile
	${REINPLACE_CMD} -e 's|^\(LDFLAGS\)=|\1+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/srg ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.post.mk>
