# New ports collection makefile for:	fcrackzip
# Date created:				16 Jul 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	fcrackzip
PORTVERSION=	0.3
CATEGORIES=	security archivers
MASTER_SITES=	http://www.goof.com/pcg/marc/data/

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Portable, fast and featureful ZIP password cracker

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETOPT_LONG=yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/fcrackzip bin/fcrackzipinfo
.if !defined(NOPORTDOCS)
MAN1=		fcrackzip.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/zipinfo/fcrackzipinfo/g' ${WRKSRC}/zipinfo.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fcrackzip ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/zipinfo ${PREFIX}/bin/fcrackzipinfo
.if !defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/fcrackzip.1 ${PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
