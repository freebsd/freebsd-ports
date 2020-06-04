# Created by: ijliao
# $FreeBSD$

PORTNAME=	txt2man
DISTVERSIONPREFIX=	txt2man-
DISTVERSION=	1.7.0
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Converts flat ASCII text to man page format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
RUN_DEPENDS=	gawk:lang/gawk

USES=		cpe gmake
CPE_VENDOR=	marc_vertes
USE_GITHUB=	yes
GH_ACCOUNT=	mvertes

MAKE_ENV=	prefix=${STAGEDIR}${PREFIX}
NO_ARCH=	yes

PLIST_FILES=	bin/bookman \
		bin/src2man \
		bin/txt2man \
		share/man/man1/bookman.1.gz \
		share/man/man1/src2man.1.gz \
		share/man/man1/txt2man.1.gz

post-patch:
	@${REINPLACE_CMD} 's,awk,gawk,' ${WRKSRC}/bookman ${WRKSRC}/src2man
	@${REINPLACE_CMD} '/exec ksh/d' ${WRKSRC}/txt2man

.include <bsd.port.mk>
