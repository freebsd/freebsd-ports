# New ports collection makefile for:    swish-e
# Date created:         		23 Feb 98
# Whom:              			Daniel O'Connor <doconnor@gsoft.com.au>
#
# $FreeBSD$
#

PORTNAME=	swish-e
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/Download/

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Simple web indexing for humans - enhanced

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

do-install:
	$(INSTALL_PROGRAM) ${WRKSRC}/src/swish-e ${PREFIX}/bin
	$(MKDIR) -p $(PREFIX)/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/README ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example1.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example2.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example3.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example4.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example5.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example6.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example7.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example8.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/conf/example9.pl ${PREFIX}/share/examples/swish-e
	$(MKDIR) -p $(PREFIX)/share/examples/swish-e/stopwords
	$(INSTALL_DATA) ${WRKSRC}/conf/stopwords/dutch.txt ${PREFIX}/share/examples/swish-e/stopwords
	$(INSTALL_DATA) ${WRKSRC}/conf/stopwords/english.txt ${PREFIX}/share/examples/swish-e/stopwords
	$(INSTALL_DATA) ${WRKSRC}/conf/stopwords/german.txt ${PREFIX}/share/examples/swish-e/stopwords
	$(INSTALL_DATA) ${WRKSRC}/conf/stopwords/spanish.txt ${PREFIX}/share/examples/swish-e/stopwords
	$(MKDIR) -p $(PREFIX)/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/CHANGES.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/INSTALL.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/README.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-3.0.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-BUGS.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-CONFIG.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-FAQ.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-LIBRARY.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-PERL.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-RUN.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/SWISH-SEARCH.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/index.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/index_long.html ${PREFIX}/share/doc/swish-e
	$(INSTALL_DATA) ${WRKSRC}/html/style.css ${PREFIX}/share/doc/swish-e
	$(MKDIR) -p $(PREFIX)/share/doc/swish-e/images
	$(INSTALL_DATA) ${WRKSRC}/html/images/dotrule1.gif ${PREFIX}/share/doc/swish-e/images
	$(INSTALL_DATA) ${WRKSRC}/html/images/swish.gif ${PREFIX}/share/doc/swish-e/images
	$(INSTALL_DATA) ${WRKSRC}/html/images/swish2.gif ${PREFIX}/share/doc/swish-e/images
	$(INSTALL_DATA) ${WRKSRC}/html/images/swish2b.gif ${PREFIX}/share/doc/swish-e/images
	$(INSTALL_DATA) ${WRKSRC}/html/images/swishbanner1.gif ${PREFIX}/share/doc/swish-e/images

.include <bsd.port.mk>
