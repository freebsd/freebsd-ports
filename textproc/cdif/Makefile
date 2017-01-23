# Created by: Yoshiro MIHIRA <sanpei@sanpei.org>
# $FreeBSD$

PORTNAME=		cdif
PORTVERSION=		1.19
CATEGORIES=		textproc
MASTER_SITES=		LOCAL/sanpei
EXTRACT_SUFX=		# empty

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Word context diff

USES=		perl5 shebangfix
SHEBANG_FILES=	${DISTNAME}

NO_WRKSUBDIR=		yes
NO_BUILD=		yes

PLIST_FILES=	bin/cdif

do-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/cdif

.include <bsd.port.mk>
