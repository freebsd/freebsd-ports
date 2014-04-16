# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	27610
PORTREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	ftp://tug.org/tex-archive/systems/texlive/tlnet/archive/
PKGNAMESUFFIX=	-infra
DISTNAME=	${PORTNAME}.infra
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Basic TeXLive infrastructure

USES=		perl5 tar:xz
USE_PERL5=	run
USE_TEX=	texlive texmf
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/TeXLive
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/web2c/
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm ${STAGEDIR}${SITE_PERL}/TeXLive
	${INSTALL_DATA} ${WRKSRC}/texmf/web2c/fmtutil-hdr.cnf \
			${WRKSRC}/texmf/web2c/updmap-hdr.cfg \
			${STAGEDIR}${PREFIX}/${TEXMFDIR}/web2c/

.include <bsd.port.mk>
