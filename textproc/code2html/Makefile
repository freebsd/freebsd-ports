# New ports collection makefile for:	code2html
# Date created:				01 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	code2html
PORTVERSION=	0.8.11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.cosy.sbg.ac.at/~ppalfrad/code2html/all/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org

RUN_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

NO_BUILD=	yes

MAN1=		code2html.1

do-configure:
	@${MV} ${WRKSRC}/code2html ${WRKSRC}/code2html.orig
	@${SED} -e 's|/usr/bin/bzip2|${PREFIX}/bin/bzip2|' \
		-e 's|/bin/gzip|/usr/bin/gzip|' \
		-e 's|/etc/code|${PREFIX}/etc/code|' \
		< ${WRKSRC}/code2html.orig > ${WRKSRC}/code2html
	@${PERL} -pi.orig -e 's|etc/code|usr/local/etc/code|' ${WRKSRC}/code2html.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/code2html.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
