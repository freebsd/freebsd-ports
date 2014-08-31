# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	34227
CATEGORIES=	print perl5
#MASTER_SITES=	ftp://tug.org/tex-archive/systems/texlive/tlnet/archive/
MASTER_SITES=	LOCAL/hrs
PKGNAMESUFFIX=	-infra
DISTNAME=	${PORTNAME}.infra.${PORTVERSION}
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Basic TeXLive infrastructure

USES=		perl5 tar:xz
USE_PERL5=	run
USE_TEX=	texmf
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/TeXLive \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c/
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm \
	    ${STAGEDIR}${SITE_PERL}/TeXLive
	${INSTALL_DATA} ${WRKSRC}/texmf-dist/web2c/fmtutil-hdr.cnf \
	    ${WRKSRC}/texmf-dist/web2c/updmap-hdr.cfg \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/web2c/

.include <bsd.port.mk>
