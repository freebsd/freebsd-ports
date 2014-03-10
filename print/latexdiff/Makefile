# Created by: Maxim Loginov <Zeliboba@mail.ru>
# $FreeBSD$

PORTNAME=	latexdiff
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support
DISTNAME=	${PORTNAME}

MAINTAINER=	Zeliboba@mail.ru
COMMENT=	Determine and mark up significant differences between latex files

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

USES=		perl5 zip
USE_PERL5=	run
NO_BUILD=	yes

MAN1=		latexdiff.1 \
		latexdiff-vc.1 \
		latexrevise.1

PLIST_FILES=	bin/latexdiff \
		bin/latexdiff-fast \
		bin/latexdiff-so \
		bin/latexdiff-vc \
		bin/latexdiff-wrap \
		bin/latexrevise

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,\/bin\/bash,${LOCALBASE}\/bin\/bash," \
	${WRKSRC}/contrib/latexdiff-wrap

do-install:
	${MKDIR} ${PREFIX}/bin ${MANPREFIX}/man/man1
	( cd ${WRKSRC} && ${INSTALL_SCRIPT} latexdiff-fast latexdiff-so \
	latexdiff-vc latexrevise contrib/latexdiff-wrap ${PREFIX}/bin && \
	${INSTALL_MAN} latexdiff.1 latexdiff-vc.1 latexrevise.1 \
	${MANPREFIX}/man/man1 )
	${LN} -s ${PREFIX}/bin/latexdiff-so ${PREFIX}/bin/latexdiff

test:
	( cd ${WRKSRC} && ${MAKE} test-so test-fast )

.include <bsd.port.mk>
