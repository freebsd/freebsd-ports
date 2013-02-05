# Created by: Murray Stokely <murray@FreeBSD.org>
# $FreeBSD$
# $NetBSD: Makefile,v 1.3 2001/09/02 19:51:38 hubertf Exp $

PORTNAME=		hugelatex
PORTVERSION=		1.0
PORTREVISION=	5
CATEGORIES=		print
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		ports@FreeBSD.org
COMMENT=		LaTeX format files with large limits

DEPRECATED=		Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=			overwrite files owned by teTex-Base which it already depends on
BUILD_DEPENDS=		tex:${PORTSDIR}/print/teTeX

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

post-install:
	${RM} ${PREFIX}/share/texmf/web2c/latex.log
	${RM} ${PREFIX}/share/texmf/web2c/latex.fmt

.include <bsd.port.mk>
