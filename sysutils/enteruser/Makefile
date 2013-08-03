# Created by: Danny Howard <dannyman@toldme.com>
# $FreeBSD$

PORTNAME=	enteruser
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dannyman.toldme.com/warez/
DISTNAME=	enteruser
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible script for adding new users

USES=		shebangfix perl5
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SHEBANG_FILES=	enteruser

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/enteruser ${PREFIX}/sbin
	${LN} -f ${PREFIX}/sbin/enteruser ${PREFIX}/sbin/queueuser

.include <bsd.port.mk>
