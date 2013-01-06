# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	discount
PORTVERSION=	2.1.1.3
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/discount/

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	A C implementation of the Markdown markup language

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=configure.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man
MAKE_JOBS_SAFE=	yes
INSTALL_TARGET=	install install.man

MAN1=		markdown.1
MAN3=		markdown.3 \
		mkd-callbacks.3 \
		mkd-functions.3 \
		mkd-line.3 \
		mkd_cleanup.3 \
		mkd_compile.3 \
		mkd_css.3 \
		mkd_doc_author.3 \
		mkd_doc_date.3 \
		mkd_doc_title.3 \
		mkd_generatecss.3 \
		mkd_generatehtml.3 \
		mkd_generateline.3 \
		mkd_in.3 \
		mkd_line.3 \
		mkd_string.3
MAN7=		markdown.7 \
		mkd-extensions.7
PLIST_FILES=	bin/markdown \
		lib/libmarkdown.a \
		include/mkdio.h

OPTIONS_DEFINE=	EXTRA TAB8 SAMPLES
OPTIONS_DEFAULT=	EXTRA TAB8

EXTRA_DESC=	Enable all extra features
TAB8_DESC=	Use a tabstop of 8 (default is 4)
SAMPLES_DESC=	Install sample programs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXTRA}
CONFIGURE_ARGS+=--enable-dl-tag \
		--enable-all-features
.endif

.if ${PORT_OPTIONS:MTAB8}
CONFIGURE_ARGS+=--with-tabstops=8
.endif

.if ${PORT_OPTIONS:MSAMPLES}
INSTALL_TARGET+=install.samples
PLIST_FILES+=	bin/makepage \
		bin/mkd2html \
		bin/theme
MAN1+=		makepage.1 \
		mkd2html.1 \
		theme.1

.endif

.include <bsd.port.mk>
