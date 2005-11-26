# New ports collection makefile for:   durep
# Date created:        14 February 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	durep
PORTVERSION=	0.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.hibernaculum.net/download/ \
		http://bsd.gubkin.ru/myports/

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Utility for monitoring disk usage in a more visual way than du

RUN_DEPENDS=	${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM

USE_PERL5=	yes
NO_BUILD=	yes
WWWDOCROOT?=	www/data
WWWCGIROOT?=	www/cgi-bin
DUREPCGI?=	${WWWCGIROOT}/durep
DUREPFILES?=	${WWWDOCROOT}/durep
DCGI=		${PREFIX}/${DUREPCGI}
DFILES=		${PREFIX}/${DUREPFILES}

MAN1=		durep.1
PLIST_FILES=	bin/durep ${DUREPCGI}/durep.cgi ${DUREPFILES}/style.css \
		${DUREPFILES}/bar.png
PLIST_DIRS=	${DUREPCGI} ${DUREPFILES}
PORTDOCS=	Artistic BUGS CHANGES README THANKS

doc:
	pod2man --center="Disk Usage Report Generator" --release="durep version ${PORTVERSION}" ${WRKSRC}/durep.pod > ${WRKSRC}/durep.1

do-install:	doc
	${INSTALL} -d ${DFILES} ${DCGI}
	${INSTALL_SCRIPT} ${WRKSRC}/durep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/durep.1 ${MAN1PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/durep.cgi ${DCGI}
	${INSTALL_DATA} ${WRKSRC}/style.css ${WRKSRC}/bar.png ${DFILES}
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S#^#${WRKSRC}/#} ${DOCSDIR}
.endif

.include <bsd.port.mk>
