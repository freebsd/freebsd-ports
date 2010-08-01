# New ports collection makefile for:	rabbit
# Date created:		2010-08-01
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rabbit
PORTVERSION=	0.6.4
CATEGORIES=	misc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/rabbit|}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An RD-document-based presentation application

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${LOCALBASE}/bin/rd2:${PORTSDIR}/textproc/ruby-rdtool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS_EN=	NEWS.en README.en
DOCS_JA=	NEWS.ja README.ja

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -pR ${WRKSRC}/sample/* ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/ja
.endfor
.endif

.include <bsd.port.mk>
