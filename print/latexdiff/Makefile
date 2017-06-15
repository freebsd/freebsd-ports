# Created by: Maxim Loginov <Zeliboba@mail.ru>
# $FreeBSD$

PORTNAME=	latexdiff
PORTVERSION=	1.2.0
CATEGORIES=	print perl5
MASTER_SITES=	TEX_CTAN/support
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Determine and mark up significant differences between latex files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 zip
USE_PERL5=	run
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
.for i in latexdiff-fast latexdiff-so latexdiff-vc latexrevise
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for m in latexdiff.1 latexdiff-vc.1 latexrevise.1
	${INSTALL_MAN} ${WRKSRC}/${m} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${LN} -s latexdiff-so ${STAGEDIR}${PREFIX}/bin/latexdiff

.include <bsd.port.mk>
