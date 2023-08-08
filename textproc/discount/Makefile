PORTNAME=	discount
PORTVERSION=	2.2.7c
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc devel
#MASTER_SITES=	https://www.pell.portland.or.us/~orc/Code/discount/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C implementation of the Markdown markup language
WWW=		https://www.pell.portland.or.us/~orc/Code/discount/ \
		https://github.com/Orc/discount

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cpe pathfix pkgconfig tar:bz2

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man --prefix=${PREFIX} --shared
CONFIGURE_SCRIPT=	configure.sh
HAS_CONFIGURE=	yes
INSTALL_TARGET=	install install.man
TEST_TARGET=	test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Orc

CONFLICTS_INSTALL=	markdown

CPE_VENDOR=	discount_project

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
