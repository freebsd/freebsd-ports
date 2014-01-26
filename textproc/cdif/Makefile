# Created by: Yoshiro MIHIRA <sanpei@sanpei.org>
# $FreeBSD$

PORTNAME=		cdif
PORTVERSION=		1.19
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sanpei
EXTRACT_SUFX=		# empty

MAINTAINER=		sanpei@FreeBSD.org
COMMENT=		Word context diff

USES=		perl5

NO_WRKSUBDIR=		yes
NO_BUILD=		yes

PLIST_FILES=	bin/cdif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}.dist

do-patch:
	${SED} -e '1s@/usr/local/bin/perl@${PERL}@' \
		< ${WRKSRC}/${DISTNAME}.dist > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/cdif

.include <bsd.port.mk>
