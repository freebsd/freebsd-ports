# New ports collection makefile for:	rabbit
# Date created:		2010-08-01
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rabbit
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	misc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/rabbit|}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An RD-document-based presentation application

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${LOCALBASE}/bin/rd2:${PORTSDIR}/textproc/ruby-rdtool

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

RUBY_SHEBANG_FILES=	bin/rabbirc bin/rabbit bin/rabbit-command \
			bin/rabbit-theme-manager bin/rabbitter bin/rabrick

DOCS_EN=	NEWS.en README.en
DOCS_JA=	NEWS.ja README.ja

pre-install:
	${RM} -f ${WRKSRC}/bin/rabbit.bat

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
