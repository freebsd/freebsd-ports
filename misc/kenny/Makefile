# Created by: Alan E <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kenny
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	https://aklv.github.io/distfiles/ \
		http://www.cgarbs.de/stuff/
DISTNAME=	${PORTNAME}.pl-${PORTVERSION}
EXTRACT_SUFX=	.gz

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Translate text both to and from KennySpeak

LICENSE=	ART10

CONFLICTS=	filters-*

USES=		perl5 shebangfix
USE_PERL5=	extract build run
SHEBANG_FILES=	${PORTNAME}
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/kenny \
		man/man1/kenny.1.gz

POD2MAN?=	${LOCALBASE}/bin/pod2man

do-build:
	@${POD2MAN} ${WRKSRC}/${PORTNAME} > ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
