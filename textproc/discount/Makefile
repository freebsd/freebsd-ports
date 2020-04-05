# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	discount
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.6
CATEGORIES=	textproc devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C implementation of the Markdown markup language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Orc

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--mandir=${MANPREFIX}/man

INSTALL_TARGET=	install install.man

CFLAGS+=	-fPIC

MAKE_JOBS_UNSAFE=	yes # libmarkdown is used before it is built

OPTIONS_DEFINE=		EXTRA TAB8 SAMPLES
OPTIONS_DEFAULT=	EXTRA TAB8

EXTRA_DESC=		Enable all extra features
TAB8_DESC=		Use a tabstop of 8 (default is 4)
SAMPLES_DESC=		Install sample programs

EXTRA_CONFIGURE_ON=	--with-dl=both --with-fenced-code --with-github-tags \
			--with-id-anchor

TAB8_CONFIGURE_ON=	--with-tabstops=8

SAMPLES_INSTALL_TARGET=	install install.samples
SAMPLES_PLIST_FILES=	bin/makepage bin/mkd2html bin/theme \
			man/man1/makepage.1.gz man/man1/mkd2html.1.gz \
			man/man1/theme.1.gz

CONFLICTS_INSTALL=	markdown

.include <bsd.port.mk>
