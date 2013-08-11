# Created by:	Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	multimarkdown
PORTVERSION=	3.7.1
PORTREVISION=	1
DISTNAME=	peg-${PORTNAME}-${PORTVERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/fletcher/peg-${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C

CONFLICTS_INSTALL=	mtools-*

LICENSE=	MIT

FETCH_ARGS=	-Fpr

USE_GMAKE=	yes
ALL_TARGET=	ALL
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/multimarkdown bin/mmd bin/mmd2all bin/mmd2odf bin/mmd2opml bin/mmd2pdf bin/mmd2tex
PORTDOCS=	LICENSE README.markdown

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E "/CFLAGS/s/-arch [[:alnum:]]+//; /CFLAGS/s/\?=/\+=/" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/multimarkdown ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DOCSDIR}
.endif

.include <bsd.port.mk>
