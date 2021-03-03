# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	discount
PORTVERSION=	2.2.7
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C implementation of the Markdown markup language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Orc

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
CONFIGURE_SCRIPT=	configure.sh
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes # libmarkdown is used before it is built
INSTALL_TARGET=	install install.man
TEST_TARGET=	test

CONFLICTS_INSTALL=	markdown

OPTIONS_DEFINE=	EXTRA SAMPLES TAB8
OPTIONS_DEFAULT=EXTRA TAB8
OPTIONS_SUB=	yes
EXTRA_DESC=	Enable all extra features
SAMPLES_DESC=	Install sample programs
TAB8_DESC=	Use a tabstop of 8 (default is 4)

EXTRA_CONFIGURE_ON=	--with-dl=both --with-fenced-code --with-github-tags --with-id-anchor
SAMPLES_INSTALL_TARGET=	install install.samples
TAB8_CONFIGURE_ON=	--with-tabstops=8

.include <bsd.port.mk>
