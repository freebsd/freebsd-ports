PORTNAME=	msort
PORTVERSION=	8.53
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sorting files in sophisticated ways

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to link: missing sbrk
BROKEN_riscv64=		fails to link: missing sbrk

LIB_DEPENDS=	libtre.so:textproc/libtre \
		libuninum.so:devel/libuninum \
		libutf8proc.so:textproc/utf8proc
RUN_DEPENDS=	iwidgets>=0:x11-toolkits/iwidgets

USES=		gettext localbase tk:wrapper,run
CONFIGURE_ENV=	ac_cv_lib_tre_regwcomp=yes
GNU_CONFIGURE=	yes
TEST_TARGET=	test

PLIST_FILES=	bin/msg bin/msort man/man1/msort.1.gz

post-patch:
	@${MV} ${WRKSRC}/limits.h ${WRKSRC}/${PORTNAME}_limits.h
	@${REINPLACE_CMD} -e 's,limits\.h,${PORTNAME}_&,' \
		${WRKSRC}/Makefile.in ${WRKSRC}/info.c \
		${WRKSRC}/input.c ${WRKSRC}/msort.c
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/RegressionTests/Makefile
	@${REINPLACE_CMD} -e 's|msort|../&|' \
		${WRKSRC}/RegressionTests/RunTests.sh

.include <bsd.port.mk>
