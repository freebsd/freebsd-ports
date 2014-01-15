# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloc
PORTVERSION=	1.60
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
EXTRACT_SUFX=	.pl

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Counts lines of code

RUN_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff

USES=		perl5
USE_PERL5=	run
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	./${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
