# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	umodunpack
PORTVERSION=	0.4
CATEGORIES=	misc
MASTER_SITES=	http://www.deepsky.com/~misaka/scripts/
DISTNAME=	${PORTNAME}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unpack umod files for Unreal and/or Unreal Tournament

USES=		perl5 shebangfix
SHEBANG_FILES=	${DISTNAME}

USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${DISTNAME}

post-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}  ${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
