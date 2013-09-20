# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	translate
PORTVERSION=	1.11
CATEGORIES=	misc
MASTER_SITES=	http://www.freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Translates string using Babelfish

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

MAN1=		translate.1
PLIST_FILES=	bin/translate

.include <bsd.port.mk>
