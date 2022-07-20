PORTNAME=	ifile
PORTVERSION=	1.3.8
CATEGORIES=	mail textproc
MASTER_SITES=	http://people.csail.mit.edu/jrennie/ifile/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application of machine learning to e-mail filtering

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

PLIST_FILES=	bin/ifile \
		man/man1/ifile.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
