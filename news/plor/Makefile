# New ports collection makefile for:	plor
# Date Created:		30 Dec 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	plor
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= system/bbs/mail

MAINTAINER=	hoek@FreeBSD.org
COMMENT=	An alpha-release reader for reading SOUP and QWK packets

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=		plor.1

DOCFILES=	../AUTHORS ../NEWS TODO plor-1.html plor-2.html \
		plor.html plor.txt

post-install:
.if !defined{NOPORTDOCS}
	@${MKDIR} ${PREFIX}/share/doc/plor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${PREFIX}/share/doc/plor
.endfor
.endif
	${INSTALL_MAN} ${FILESDIR}/plor.1 ${PREFIX}/man/man1/plor.1
	perl -pi -e '$$a = '\''${PREFIX}/share/doc/plor/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${PREFIX}/man/man1/plor.1

.include <bsd.port.mk>
