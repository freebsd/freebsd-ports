PORTNAME=	mmv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10
CATEGORIES=	misc

MAINTAINER=	se@FreeBSD.org
COMMENT=	Move/Copy/Append/Link multiple files
WWW=		https://github.com/rrthomas/mmv

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gengetopt>=2.23:devel/gengetopt \
		gnulib>0;:devel/gnulib \
		help2man:misc/help2man

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rrthomas
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
		${RMDIR} ${WRKSRC}/gnulib && ${LN} -s ${LOCALBASE}/share/gnulib ${WRKSRC}/

pre-configure:
		cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
