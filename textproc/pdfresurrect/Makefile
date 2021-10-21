PORTNAME=	pdfresurrect
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analyze and extract older versions of a pdf from the current pdf

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	enferex

PLIST_FILES=	bin/pdfresurrect \
		man/man1/pdfresurrect.1.gz

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pdfresurrect

.include <bsd.port.mk>
