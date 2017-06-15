# Created by: Aleksander Fafula <alex@bsdguru.org>
# $FreeBSD$

PORTNAME=	fortunepl
PORTVERSION=	20091121
CATEGORIES=	polish
MASTER_SITES=	ftp://master-ftp.pld-linux.org/${F_SUBDIR}/ \
		ftp://ftp.atm.pld-linux.org/${F_SUBDIR}/ \
		ftp://ftp.icm.edu.pl/pub/linux/distributions/pld-linux/${F_SUBDIR}/ \
		ftp://distrib-coffee.ipsl.jussieu.fr/pub/linux/pld/${F_SUBDIR}/ \
		ftp://ftp.heanet.ie/pub/pld-linux/${F_SUBDIR}/
F_SUBDIR=	pool/f/fortunes-pl
DISTFILES=	fortunes-pl-${PORTVERSION}-3.src.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lot of funny Polish fortune files

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/fortunes-pl-${PORTVERSION}

.if exists(/usr/games/strfile)
STRCMD=		/usr/games/strfile
.elif exists(/usr/bin/strfile)
STRCMD=		/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif

post-extract:
	@(cd ${WRKDIR} && ${TAR} zxf fortunes-pl-${PORTVERSION}.tar.bz2)

do-build:
	(cd ${WRKSRC} && ${FIND} . -type f -exec ${STRCMD} {} \;)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/pl
	${INSTALL_DATA} ${WRKSRC}/* \
		${STAGEDIR}${PREFIX}/share/games/fortune/pl

.include <bsd.port.mk>
