# New ports collection makefile for:	Markdown
# Date created:		13 October 2005
# Whom:			Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	markdown
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://daringfireball.net/projects/downloads/
DISTNAME=	Markdown_${PORTVERSION}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A text-to-HTML conversion tool for web writers

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
