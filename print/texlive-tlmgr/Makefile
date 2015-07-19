# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20150523
CATEGORIES=	print perl5
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMESUFFIX=	-tlmgr
DISTNAME=	${PORTNAME}-${PORTVERSION}-extra
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeXLive manager modules

USES=		perl5 tar:xz
USE_PERL5=	run
USE_TEX=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm \
	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/.texlive-tlmgr

.include <bsd.port.mk>
