PORTNAME=	dim
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://glyphobet.net/dim/
DISTNAME=	dim
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Directory lister which sorts the file list in 2D
WWW=		https://glyphobet.net/dim/dim.html

LICENSE=	GPLv2+

DEPRECATED=	Abandonware, upstream stopped development in 2005
EXPIRATION_DATE=2023-04-30

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		shebangfix perl5
SHEBANG_FILES=	dim.pl
USE_PERL5=	run

PLIST_FILES=	bin/dim

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dim.pl ${STAGEDIR}${PREFIX}/bin/dim

.include <bsd.port.mk>
