# Created by: ijliao
# $FreeBSD$

PORTNAME=	txtbdf2ps
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://oldrus-ispell.sourceforge.net/
EXTRACT_SUFX=	.txt

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Translator TXT + BDF to PS

PROJECTHOST=	ak-various-projects

PLIST_FILES=	bin/txtbdf2ps
USES=		perl5 shebangfix
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
SHEBANG_FILES=	${DISTNAME}.txt
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.txt ${STAGEDIR}${PREFIX}/bin/txtbdf2ps

.include <bsd.port.mk>
