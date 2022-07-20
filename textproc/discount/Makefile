PORTNAME=	discount
PORTVERSION=	2.2.7b
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C implementation of the Markdown markup language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cpe pkgconfig

CPE_VENDOR=	discount_project

USE_GITHUB=	yes
GH_ACCOUNT=	Orc

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man --prefix=${PREFIX} --shared
CONFIGURE_SCRIPT=	configure.sh
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes # libmarkdown is used before it is built
INSTALL_TARGET=	install install.man
TEST_TARGET=	test
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	markdown

PORTSCOUT=	skipv:2.2.7

OPTIONS_DEFINE=	EXTRA SAMPLES TAB8
OPTIONS_DEFAULT=EXTRA TAB8
OPTIONS_SUB=	yes
EXTRA_DESC=	Enable all extra features
SAMPLES_DESC=	Install sample programs
TAB8_DESC=	Use a tabstop of 8 (default is 4)

EXTRA_CONFIGURE_ON=	--with-dl=both --with-fenced-code --with-github-tags --with-id-anchor
SAMPLES_INSTALL_TARGET=	install.samples
TAB8_CONFIGURE_ON=	--with-tabstops=8

post-install:
	${INSTALL_DATA} ${WRKSRC}/libmarkdown.a ${STAGEDIR}${PREFIX}/lib/libmarkdown.a
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmarkdown.so

.include <bsd.port.mk>
