# New ports collection makefile for:	code2html
# Date created:				01 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	code2html
PORTVERSION=	0.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.palfrader.org/code2html/all/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Sourcecode to HTML converter

.if !exists(/usr/bin/bzip2)
RUN_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

BZIP2BASE=	${PREFIX}
.else
BZIP2BASE=	/usr
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes

MAN1=		code2html.1
PLIST_FILES=	bin/code2html

do-configure:
	@${MV} ${WRKSRC}/code2html ${WRKSRC}/code2html.orig
	@${SED} -e 's|/usr/bin/bzip2|${BZIP2BASE}/bin/bzip2|' \
		-e 's|/bin/gzip|/usr/bin/gzip|' \
		-e 's|/etc/code|${PREFIX}/etc/code|' \
		< ${WRKSRC}/code2html.orig > ${WRKSRC}/code2html
	@${REINPLACE_CMD} -e 's|/etc/code|${PREFIX}/etc/code|' \
	    ${WRKSRC}/code2html.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/code2html.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
