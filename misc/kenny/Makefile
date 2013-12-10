# Created by: Alan E <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kenny
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}\
				http://www.cgarbs.de/stuff/
DISTNAME=	${PORTNAME}.pl-${PORTVERSION}
EXTRACT_SUFX=	.gz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Translate text both to and from KennySpeak

PROJECTHOST=	ak-various-projects

CONFLICTS=	filters-*

USES=		perl5
USE_PERL5=	extract build run
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/kenny \
		man/man1/kenny.1.gz

POD2MAN?=	${LOCALBASE}/bin/pod2man

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/${PORTNAME}
	@${POD2MAN} ${WRKDIR}/${PORTNAME} > ${WRKDIR}/${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
