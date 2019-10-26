# Created by: Danny Howard <dannyman@toldme.com>
# $FreeBSD$

PORTNAME=	enteruser
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dannyman.toldme.com/warez/
DISTNAME=	enteruser
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Extensible script for adding new users

LICENSE=	BSD2CLAUSE

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	enteruser

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/enteruser ${STAGEDIR}${PREFIX}/sbin
	@cd ${STAGEDIR}${PREFIX}/sbin && ${LN} -sf enteruser queueuser

.include <bsd.port.mk>
