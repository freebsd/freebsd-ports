PORTNAME=	fcrackzip
DISTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	security archivers

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Portable, fast, and featureful ZIP password cracker
WWW=		http://home.schmorp.de/marc/fcrackzip.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libzip.so:archivers/libzip

USES=		perl5 localbase:ldflags
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	hyc
GH_TAGNAME=	c713631

GNU_CONFIGURE=	yes

LDFLAGS+=	-lzip

PLIST_FILES=	bin/fcrackzip bin/fcrackzipinfo share/man/man1/fcrackzip.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/zipinfo/fcrackzipinfo/g' ${WRKSRC}/zipinfo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcrackzip ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/zipinfo \
		${STAGEDIR}${PREFIX}/bin/fcrackzipinfo
	${INSTALL_MAN} ${WRKSRC}/fcrackzip.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
