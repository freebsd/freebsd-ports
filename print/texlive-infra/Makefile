# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	27610
CATEGORIES=	print perl5
MASTER_SITES=	ftp://tug.org/tex-archive/systems/texlive/tlnet/archive/
PKGNAMESUFFIX=	-infra
DISTNAME=	${PORTNAME}.infra
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Basic TeXLive infrastructure

USE_XZ=		yes
USE_TEX=	texlive texmf
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-install:
	${MKDIR} ${SITE_PERL}/TeXLive
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm ${SITE_PERL}/TeXLive
	${INSTALL_DATA} ${WRKSRC}/texmf/web2c/fmtutil-hdr.cnf \
			${WRKSRC}/texmf/web2c/updmap-hdr.cfg \
			${PREFIX}/${TEXMFDIR}/web2c/

.include <bsd.port.mk>
