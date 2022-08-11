PORTNAME=	fcrackzip
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security archivers
MASTER_SITES=	http://oldhome.schmorp.de/data/marc/ \
		http://distfiles.macports.org/${PORTNAME}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Portable, fast, and featureful ZIP password cracker

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		perl5
USE_PERL5=	build

PLIST_FILES=	bin/fcrackzip bin/fcrackzipinfo man/man1/fcrackzip.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/zipinfo/fcrackzipinfo/g' ${WRKSRC}/zipinfo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcrackzip ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/zipinfo \
		${STAGEDIR}${PREFIX}/bin/fcrackzipinfo
	${INSTALL_MAN} ${WRKSRC}/fcrackzip.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
