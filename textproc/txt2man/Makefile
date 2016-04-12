# Created by: ijliao
# $FreeBSD$

PORTNAME=	txt2man
PORTVERSION=	1.5.6
CATEGORIES=	textproc
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts flat ASCII text to man page format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe gmake
MAKE_ENV=	prefix=${STAGEDIR}${PREFIX}
NO_ARCH=	yes

CPE_VENDER=	marc_vertes

PLIST_FILES=	bin/bookman bin/src2man bin/txt2man \
		man/man1/bookman.1.gz man/man1/src2man.1.gz man/man1/txt2man.1.gz

post-patch:
	@${REINPLACE_CMD} 's,awk,gawk,' ${WRKSRC}/bookman ${WRKSRC}/src2man
	@${REINPLACE_CMD} '/exec ksh/d' ${WRKSRC}/txt2man

.include <bsd.port.mk>
