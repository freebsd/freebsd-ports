# $FreeBSD$

PORTNAME=	pdfresurrect
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analyze and extract older versions of a pdf from the current pdf

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	enferex
USE_LDCONFIG=	yes

PLIST_FILES=	bin/pdfresurrect \
		man/man1/pdfresurrect.1.gz

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pdfresurrect

.include <bsd.port.mk>
