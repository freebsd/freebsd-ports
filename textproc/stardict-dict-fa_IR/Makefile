PORTNAME=	stardict-dict-fa_IR
PORTVERSION=	1.0.0
CATEGORIES=	textproc
MASTER_SITES=	SF/pyglossary/dic/English-Persion/
DISTNAME=	Open%20Dictionary%20aka%20QueerDick-2010-09-28-rich
DIST_SUBDIR=	stardict

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	English-Persian dictionary for stardict
WWW=		http://pyglossary.sourceforge.net

WRKSRC=		"${WRKDIR}/Open Dictionary aka QueerDick-2010-09-28-rich"

NO_ARCH=	yes
NO_BUILD=	yes

DICTDIR=	share/stardict/dic

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${DICTDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${DICTDIR}

.include <bsd.port.mk>
