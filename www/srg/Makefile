# New ports collection makefile for:	srg
# Date created:		28 June 2004
# Whom:			Dmitry Semkin <lslarry@gmail.ru>
#
# $FreeBSD$
#

PORTNAME=	srg
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://mirror.crc.net.nz/pub/srg/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lslarry@gmail.ru
COMMENT=	A Squid Report Generator

USE_GMAKE=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
NO_INSTALL_MANPAGES=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}"

PLIST_FILES=	bin/srg
.for i in footer.php header.php ip2user.txt srg.conf
PLIST_FILES+=	share/examples/srg/${i}
.endfor
PLIST_DIRS=	share/examples/srg

post-patch:
	${REINPLACE_CMD} -e 's|-g |${CFLAGS} |' ${WRKSRC}/Makefile \
		${WRKSRC}/lib/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/srg ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
