# New ports collection makefile for:	fswiki
# Date created:		Oct 10, 2004
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	fswiki
PORTVERSION=	3.5.11
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	fswiki/19822
DISTNAME=	wiki${PORTVERSION:S|.|_|g}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	FreeStyle Wiki (perl based wiki clone)

RUN_DEPENDS=	${JCODE}:${PORTSDIR}/japanese/p5-Jcode \
	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template

USE_ZIP=	yes
USE_PERL5=	yes
NO_BUILD=	yes

post-extract:
	${SED} -e 's|__DATADIR__|${DATADIR}|' ${FILESDIR}/setup.sh \
		>${WRKSRC}/setup.sh

do-install:
	-${MKDIR} ${DATADIR}
	cd ${WRKSRC}; \
	for d in `${FIND} * -type d`; do \
		${MKDIR} ${DATADIR}/$${d}; \
	done
	cd ${WRKSRC}; \
	for i in `${FIND} . -type f | ${GREP} -v .orig`; do \
		${INSTALL_DATA} $${i} ${DATADIR}/$${i}; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/wiki.cgi ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${DATADIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
JCODE=	${SITE_PERL}/${PERL_ARCH}/Jcode.pm
.else
JCODE=	${SITE_PERL}/Jcode.pm
.endif

.include <bsd.port.post.mk>
