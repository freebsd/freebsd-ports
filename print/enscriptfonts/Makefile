# Created by: kline
# $FreeBSD$

PORTNAME=	enscriptfonts
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://muuz.deadbbs.com/FreeBSD/xenscript/
DISTNAME=	enscript_fonts-0.81
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	More than 120 free- and share-ware fonts to extend enscript-1.5

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_WRKSUBDIR=	YES
NO_MANCOMPRESS=	YES
NO_BUILD=	YES
SUB_FILES+=	pkg-message

# user should choose their own version
#RUN_DEPENDS=	enscript:print/enscript-letter

do-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKSRC}/font.map ${STAGEDIR}${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKSRC}/*.afm ${STAGEDIR}${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKSRC}/*.readme ${STAGEDIR}${PREFIX}/share/enscript/xenscript

.include <bsd.port.mk>
