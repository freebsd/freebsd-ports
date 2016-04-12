# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	info2man
PORTVERSION=	20040717
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.cskk.ezoshosting.com/cs/css/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into man pages

RUN_DEPENDS=	p5-Perl4-CoreLibs>0:devel/p5-Perl4-CoreLibs
USES=		perl5 shebangfix
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLSCRIPTS=	info2man info2pod
SHEBANG_FILES=	info2pod

pre-configure:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/info2pod

do-install:
	${INSTALL_SCRIPT} ${PLSCRIPTS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} cs ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
