# New ports collection makefile for:    hugelatex
# Date created:         7 September 2001
# Whom:                 Murray Stokely <murray@FreeBSD.org>
#
# $FreeBSD$
#
# $NetBSD: Makefile,v 1.3 2001/09/02 19:51:38 hubertf Exp $
#

PORTNAME=		hugelatex
PORTVERSION=		1.0
CATEGORIES=		print
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		murray@FreeBSD.org
COMMENT=	LaTeX format files with large limits

BUILD_DEPENDS=		tex:${PORTSDIR}/print/teTeX

BROKEN=			Incomplete pkg-plist

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

TEXMF_CNF=		${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-hugelatex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd `dirname ${TEXMF_CNF}`; \
	${ECHO_CMD} "" | ${PREFIX}/bin/latex -ini -fmt=hugelatex -progname=hugelatex latex.ini || ${TRUE}; \
	${RM} -f texsys.aux
	${RM} -f ${PREFIX}/bin/hugelatex
	${LN} -s latex ${PREFIX}/bin/hugelatex
	${PREFIX}/bin/mktexlsr

.include <bsd.port.mk>
