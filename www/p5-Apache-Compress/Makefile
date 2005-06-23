# New ports collection makefile for:	p5-Apache-Compress
# Date created:				Sep 09 2003
# Whom:	      				Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Compress
PORTVERSION=	1.005
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache/KWILLIAMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	martin@matuska.org
COMMENT=	Auto-compress web files with Gzip

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib

PERL_CONFIGURE=	yes

MAN3=		Apache::Compress.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${DOCSDIR}
.endif

.include <bsd.port.mk>
