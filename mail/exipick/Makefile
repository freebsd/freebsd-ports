# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	exipick
PORTVERSION=	20100323.0
CATEGORIES=	mail
MASTER_SITES=	http://jetmore.org/john/code/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display messages from Exim queue based on a variety of criteria

PLIST_FILES=	bin/${PORTNAME}

USES=		perl5 shebangfix
SHEBANG_FILES=	${DISTNAME}
USE_PERL5=	run
NO_BUILD=	yes

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's;\/local\/exim\/spool;\/var\/spool\/exim;g' \
		${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
