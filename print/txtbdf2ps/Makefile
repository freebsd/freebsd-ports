# Created by: ijliao
# $FreeBSD$

PORTNAME=	txtbdf2ps
PORTVERSION=	0.7.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://oldrus-ispell.sourceforge.net/
EXTRACT_SUFX=	.txt

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Translator TXT + BDF to PS

PROJECTHOST=	ak-various-projects

PLIST_FILES=	bin/txtbdf2ps
USES=		perl5
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/${DISTNAME}.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.txt ${PREFIX}/bin/txtbdf2ps

.include <bsd.port.mk>
