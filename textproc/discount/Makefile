# New ports collection makefile for:	discount
# Date created:				2009-04-22
# Whom:					Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	discount
PORTVERSION=	2.0.8
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/markdown/

MAINTAINER=	kimelto@gmail.com
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

OPTIONS=	EXTRA "Enable all extra features" on \
		TAB8 "Use a tabstop of 8 (default is 4)" on
.include <bsd.port.pre.mk>

.ifdef (WITH_EXTRA)
CONFIGURE_ARGS+=--enable-dl-tag \
		--enable-all-features
.endif

.ifdef (WITH_TAB8)
CONFIGURE_ARGS+=--with-tabstops=8
.endif

.include <bsd.port.post.mk>
