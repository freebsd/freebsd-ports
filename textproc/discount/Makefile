# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	discount
DISTVERSION=	2.1.6
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/discount/ \
		LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	A C implementation of the Markdown markup language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=configure.sh
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man
INSTALL_TARGET=	install install.man

PLIST_FILES=	bin/markdown lib/libmarkdown.a include/mkdio.h \
		man/man1/markdown.1.gz man/man3/markdown.3.gz \
		man/man3/mkd-callbacks.3.gz man/man3/mkd-functions.3.gz \
		man/man3/mkd-line.3.gz man/man3/mkd_cleanup.3.gz \
		man/man3/mkd_compile.3.gz man/man3/mkd_css.3.gz \
		man/man3/mkd_doc_author.3.gz man/man3/mkd_doc_date.3.gz \
		man/man3/mkd_doc_title.3.gz man/man3/mkd_generatecss.3.gz \
		man/man3/mkd_generatehtml.3.gz man/man3/mkd_generateline.3.gz \
		man/man3/mkd_in.3.gz man/man3/mkd_line.3.gz \
		man/man3/mkd_string.3.gz man/man7/markdown.7.gz \
		man/man7/mkd-extensions.7.gz

OPTIONS_DEFINE=	EXTRA TAB8 SAMPLES
OPTIONS_DEFAULT=	EXTRA TAB8

EXTRA_DESC=	Enable all extra features
TAB8_DESC=	Use a tabstop of 8 (default is 4)
SAMPLES_DESC=	Install sample programs

EXTRA_CONFIGURE_ON=	--with-dl=both --with-fenced-code --with-github-tags \
			--with-id-anchor

TAB8_CONFIGURE_ON=	--with-tabstops=8

SAMPLES_INSTALL_TARGET=	install install.samples
SAMPLES_PLIST_FILES=	bin/makepage bin/mkd2html bin/theme \
			man/man1/makepage.1.gz man/man1/mkd2html.1.gz \
			man/man1/theme.1.gz

.include <bsd.port.mk>
