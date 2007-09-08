# New ports collection makefile for:	Markdown
# Date created:		13 October 2005
# Whom:			Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	markdown
PORTVERSION=	1.0.1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://daringfireball.net/projects/downloads/
DISTNAME=	Markdown_${PORTVERSION}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A text-to-HTML conversion tool for web writers

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ZIP=	yes
USE_PERL5=	yes
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	License.text Markdown-Readme.text
.endif

PLIST_FILES=	bin/markdown

post-patch:
	${PERL} -pi -e "s#/usr/bin/perl#${PERL}#" ${WRKSRC}/Markdown.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${PREFIX}/bin/markdown
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} "${WRKSRC}/License.text" ${DOCSDIR}/License.text
	${INSTALL_DATA} "${WRKSRC}/Markdown Readme.text" ${DOCSDIR}/Markdown-Readme.text
.endif

.include <bsd.port.mk>
